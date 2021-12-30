/Code manufactured by A.M GreHiDeL
#include <IRremote.h>
int signal_pin=7;
int led=8;
IRrecv irrecv(signal_pin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling the signal pin");
  irrecv.enableIRIn();
  Serial.println("Signal pin enabled successfully");
  pinMode(led,OUTPUT);
}
void loop()
{
  if(irrecv.decode(&results))
  {
    Serial.println(results.value,HEX);
    irrecv.resume();
}
}
