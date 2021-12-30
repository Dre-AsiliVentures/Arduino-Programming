/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int servo_vcc=53;
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(52);  // attaches the servo on pin 9 to the servo object
  pinMode(servo_vcc,OUTPUT);
  Serial.begin(9600);
  digitalWrite(servo_vcc,HIGH);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);// waits 15ms for the servo to reach the position
    Serial.println(pos);
    if (pos==180)
    {
      digitalWrite(servo_vcc,LOW);
    }
    else
    {
       digitalWrite(servo_vcc,HIGH);
    }
  }

}
