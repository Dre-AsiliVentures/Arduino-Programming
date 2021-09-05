#include <Servo.h>
const int servo_pin=52;// define the servo pin
Servo myservo; //create an object called myservo from the Servo class

void setup() {
  // put your setup code here, to run once:
myservo.attach(servo_pin);// define the pin the servo is attached to
}

void loop() {
  // put your main code here, to run repeatedly:
myservo.write(0); // let the servo be at 0 degrees
delay(100); //wait for 100 miliseconds
myservo.write(90); //let the servo be at 90 degrees
delay(100); //wait for 100 miliseconds
}
