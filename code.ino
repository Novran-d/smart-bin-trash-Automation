#include <Servo.h>

Servo servo;

void setup()
{
  Serial.begin(9600);
  servo.attach(4);
}

void loop()
{
  pinMode(13, OUTPUT);
  
  digitalWrite(13, LOW);
  //delayMicroseconds(5);
  digitalWrite(13, HIGH);
  //delayMicroseconds(5);
  digitalWrite(13, LOW);
  
  pinMode(13, INPUT);
  int duration = pulseIn(13, HIGH);
  Serial.println(duration);
  int cm = duration / 87;
  
  Serial.println(cm);
  
  if(cm <=25){
  	servo.write(0);
  }
  else if(cm <= 50){
  	servo.write(30);
  }
  else if(cm <= 100){
  	servo.write(50);
  }
  else if(cm <= 150){
  	servo.write(70);
  }
  else if(cm <= 170){
  	servo.write(100);
  }
  else if(cm <= 200){
  	servo.write(130);
  }
  else if(cm <= 250){
  	servo.write(150);
  }
  else{
  	servo.write(180);
  }
  delay(100);
}
