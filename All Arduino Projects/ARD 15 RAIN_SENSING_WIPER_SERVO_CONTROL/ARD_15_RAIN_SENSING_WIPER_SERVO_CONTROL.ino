#include <Servo.h>
int servo_pin=9;
int servo_position=0;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
myservo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
for(servo_position=0;servo_position<=180;servo_position++)
{
myservo.write(servo_position);
delay(200);
}
delay(100);
for(servo_position=180;servo_position>0;servo_position--)
{
myservo.write(servo_position);
delay(200);
}
}
