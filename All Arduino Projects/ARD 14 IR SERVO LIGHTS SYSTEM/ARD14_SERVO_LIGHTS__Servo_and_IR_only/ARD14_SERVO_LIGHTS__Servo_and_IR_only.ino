//Code manufactured by A.M GreHiDeL
#include <Servo.h>
#include <IRremote.h>
int signal_pin=50;
int servo_vcc=52;
int red_led=48;
int yellow_led=46;
IRrecv irrecv(signal_pin);
decode_results results;
Servo myservo;//
void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling the signal pin");
  irrecv.enableIRIn();
  myservo.attach(11);
  Serial.println("Signal pin enabled successfully");
  pinMode(servo_vcc,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(yellow_led,OUTPUT);
}
void loop()
{
if (irrecv.decode(&results))
  {
    switch(results.value)
    {
      case 0xFF28D7:// Power ON Button
      digitalWrite(red_led,HIGH);
      digitalWrite(servo_vcc,HIGH);
    }
    irrecv.resume();
    switch(results.value)
    {
      //Serial.println("Nimewasha servo");
      case 0xFFA857:// STOP Button
      digitalWrite(servo_vcc,LOW);
      digitalWrite(red_led,LOW);
      digitalWrite(yellow_led,LOW);
    }
     irrecv.resume();
     switch(results.value)
    {
      case 0xFFB847:// UP Button
      //servo write angle
      digitalWrite(yellow_led,HIGH);
      myservo.write(15);
      delay(150);
      digitalWrite(servo_vcc,LOW);
      digitalWrite(red_led,LOW);
          
    }
     irrecv.resume();
     switch(results.value)
    {
      case 0xFF48B7:// Down Button
      //servo write angle
      digitalWrite(yellow_led,HIGH);
      myservo.write(0);
      delay(150);
      digitalWrite(servo_vcc,LOW);
      digitalWrite(red_led,LOW);
    }
     irrecv.resume();

  }
}
