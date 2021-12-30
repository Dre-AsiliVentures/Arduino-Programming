//Manufactured by the ElectronicsDr
#include <IRremote.h>
int RECV_PIN = 7;
int led=8;
IRrecv irrecv(RECV_PIN);
decode_results results;
long int values=results.value;
#define one 1086292095
#define two 1086259455
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
   if(results.value==two)
   {
    digitalWrite(led,HIGH);
   }
   if(results.value==one)
   {
    digitalWrite(led,LOW);
   }
    irrecv.resume ();
  }
  delay(100);
}
