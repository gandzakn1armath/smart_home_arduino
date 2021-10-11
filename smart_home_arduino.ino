#include <Servo.h>
#include <Keypad.h>

Servo myservo;
bool isDoorOpen = false;
const int buzzer = 4;
int led1pin1 = 2;
int led1pin2 = 3;
int led2pin1 = 8;
int led2pin2 = 9;
int led3pin1 = 11;
int led3pin2 = 12;


const byte ROWS = 4; 
const byte COLS = 4; 
String key  = "";
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {21,20,19,18}; 
byte colPins[COLS] = {17,16,15,14}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void blueOn(){
  digitalWrite(led1pin1, LOW);
  digitalWrite(led1pin2, HIGH); 
 }
void blueOff(){
   digitalWrite(led1pin1, LOW);
   digitalWrite(led1pin2, LOW); 
 }

void orangeOn(){
  digitalWrite(led2pin1, LOW);
  digitalWrite(led2pin2, HIGH);
}
void greenOn(){
  digitalWrite(led3pin1, HIGH);
  digitalWrite(led3pin2, LOW);
}


void orangeOff(){
  digitalWrite(led2pin1, LOW);
  digitalWrite(led2pin2, LOW);
 }
void greenOff(){
  digitalWrite(led3pin1, LOW);
  digitalWrite(led3pin2, LOW);
  }
void buzzerOn(){
tone(buzzer, 1000);    
}
void buzzerOff(){
 noTone(buzzer);  
}

void doorOpen(){
  myservo.write(140); 
}
void doorClose(){
  myservo.write(0); 
}

void allLightsOff(){
  blueOff();
  delay(200);
  orangeOff();
  delay(200);
  greenOff();
}

void allLightsOn(){
  greenOn();
  delay(200);
  orangeOn();
  delay(200);
  blueOn();
}

void doorState(){
if (isDoorOpen){
  doorClose();
  allLightsOff();
  isDoorOpen = false;
}else{
  doorOpen();
  allLightsOn();
  isDoorOpen = true;
}
}
void setup() {
  Serial.begin(9600);
  myservo.attach(10);
  pinMode(led1pin1, OUTPUT);
  pinMode(led1pin2, OUTPUT);
  pinMode(led2pin1, OUTPUT);
  pinMode(led2pin2, OUTPUT);
  pinMode(led3pin1,OUTPUT);
  pinMode(led3pin2,OUTPUT);
  pinMode(buzzer, OUTPUT);
  doorClose();
}


void loop() {
 char customKey = customKeypad.getKey();
 if (customKey){
 
  Serial.println(customKey);
  if (customKey == 'D'){
     Serial.println(key);
     if(key.equals("2")){
        doorState(); 
          
     }else{
      buzzerOn();
      delay (1000);
      buzzerOff();
      }
     key = "";
  }else{
     
      key = key + customKey; 
       
  }
 }


}
