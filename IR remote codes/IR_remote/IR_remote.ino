#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
const int RECV_PIN=11;
int remote_pin=6;
IRrecv irrecv(RECV_PIN);
decode_results results;
int pin=6;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  digitalWrite(remote_pin,HIGH);
  irrecv.enableIRIn();//start receiver
  irrecv.blink13(true);
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
