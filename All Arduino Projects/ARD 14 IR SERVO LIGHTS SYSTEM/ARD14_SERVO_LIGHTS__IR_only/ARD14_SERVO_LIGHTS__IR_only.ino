//Code manufactured by A.M GreHiDeL
#include <IRremote.h>
int signal_pin=50;
int servo_vcc=52;
IRrecv irrecv(signal_pin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling the signal pin");
  irrecv.enableIRIn();
  Serial.println("Signal pin enabled successfully");
  pinMode(servo_vcc,OUTPUT);
}
void loop()
{
if (irrecv.decode(&results))
  {
    switch(results.value)
    {
      case 0xFF28D7:// Power ON Button
      digitalWrite(servo_vcc,HIGH);
    }
    irrecv.resume();
    switch(results.value)
    {
      //Serial.println("Nimewasha servo");
      case 0xFFA857:// STOP Button
      digitalWrite(servo_vcc,LOW);
    }
     irrecv.resume();
     switch(results.value)
    {
      case 0xFFB847:// UP Button
      //servo write angle
      digitalWrite(servo_vcc,LOW);
    }
     irrecv.resume();
     switch(results.value)
    {
      case 0xFF48B7:// Down Button
      //servo write angle
      digitalWrite(servo_vcc,LOW);
    }
     irrecv.resume();

  }
}
