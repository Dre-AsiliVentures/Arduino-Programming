//Manufactured by A.M GreHiDeL
#include <IRremote.h>

int RECV_PIN = 7;
int led=8;
IRrecv irrecv(RECV_PIN);

decode_results results;
//char val=results.value;
void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(led,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results))
  {
    switch(results.value)
    {
      case 0xFFB04F:
      digitalWrite(led,HIGH);
      
    }
       switch(results.value)
    {
      case 0xFFA857:
      digitalWrite(led,LOW);
      
    }
    irrecv.resume ();
  }
  
  delay(100);
}
