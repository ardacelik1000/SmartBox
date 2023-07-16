#include <Servo.h>   
#include <Arduino.h>
Servo servo;
int triggerPin = 5;
int echoPin = 6;
int servoPin = 7;
long time;
int distance ;
void setup()
{
  servo.attach(servoPin);
  servo.write(0);
  delay(2000);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop(){ 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  time = pulseIn(echoPin, HIGH);  
  distance = time * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if ( distance <= 50 ){  
    servo.write(135);
    delay(3000); 
  }else{  
    servo.write(45);
  }
}
