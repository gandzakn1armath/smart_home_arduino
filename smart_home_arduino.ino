const int buzzer = 4;
int led1pin1 = 2;
int led1pin2 = 3;
int led2pin1 = 8;
int led2pin2 = 9;
int led3pin1 = 11;
int led3pin2 = 12;

void blueOn(){
  digitalWrite(led1pin1, LOW);
  digitalWrite(led1pin2, HIGH); 
 }

void orangeOn(){
digitalWrite(led2pin1, LOW);
  digitalWrite(led2pin2, HIGH);
 }
void greenOn(){
  digitalWrite(led3pin1, HIGH);
  digitalWrite(led3pin2, LOW);
  }

void blueOff(){
 digitalWrite(led1pin1, HIGH);
 digitalWrite(led1pin2, LOW); 
 }

void orangeOff(){
digitalWrite(led2pin1, HIGH);
  digitalWrite(led2pin2, LOW);
 }
void greenOff(){
  digitalWrite(led3pin1, LOW);
  digitalWrite(led3pin2, HIGH);
  }
void buzzerOn(){
tone(buzzer, 1000);    
}
void buzzerOff(){
 noTone(buzzer);  
}
void setup() {
  // put your setup code here, to run once:
  pinMode(led1pin1, OUTPUT);
  pinMode(led1pin2, OUTPUT);
  pinMode(led2pin1, OUTPUT);
  pinMode(led2pin2, OUTPUT);
  pinMode(led3pin1,OUTPUT);
  pinMode(led3pin2,OUTPUT);
  pinMode(buzzer, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:   
 blueOn();
 delay(1000);
 orangeOn();
 delay(1000); 
 greenOn();
 delay(1000); 
 blueOff();
 delay(1000);
 orangeOff();
 delay(1000); 
 greenOff();
 delay(1000); 

  
 

  
  
  
  
     
}
