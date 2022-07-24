#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3,4); // trigger, echo

#include <Servo.h>
Servo s = Servo();

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup() {
  // put your setup code here, to run once:
  s.attach(2);  // servo

  // Motor A
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  analogWrite(ENA,250);

  // Motor B
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  analogWrite(ENB,250);

  // LED
  pinMode(8,OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int x = Serial.read();

  digitalWrite(8,HIGH);

  // next
  digitalWrite(13,HIGH); 
  digitalWrite(12,LOW);
  delay(300);
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  delay(300);
  

  

  
  // Forward
  if (x == '1'){
    s.write(90);
    delay(300);
    int d = u.read();
    if( d > 20 ){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      delay(1000);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
      }
    }

  // Reverse 
  if (x == '2'){
    int d = u.read();
    if( d > 20 ){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      delay(1000);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
      }
    } 

  // Turn Left
  if (x == '3'){
    s.write(135);
    delay(300);
    int d = u.read();
    if( d > 20 ){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      delay(1000);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
      }
      s.write(90);
    } 

  // Turn Right
  if (x == '4'){
    s.write(45);
    delay(300);
    int d = u.read();
    if( d > 20 ){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      delay(1000);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
      }
      s.write(90);
    }   

  // Stop
  if (x == '5'){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
    }

   int d = u.read();
   if ( d < 20 ){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    }   

}
