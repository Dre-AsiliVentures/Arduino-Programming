/* This code has been made by GreHiDel 
you need the ardruino IR remote master to run this code*/
//#include <boarddefs.h>
#include <IRremote.h>
//#include <IRremoteInt.h>
//#include <ir_Lego_PF_BitStreamEncoder.h>
# define redLED 9
# define greenLED 8
# define buzzer 7
# define fan 6
# define MAX_TIME 150
# define smoke_sensor A5
int sensorThres=170;
long lastPressTime=0;
int state;
IRrecv irrecv (11);// declares the IRrecv as irrecv and assigns it to digital pin 4
decode_results results; 
void setup() {
  // put your setup code here, to run once:
  pinMode(smoke_sensor,INPUT);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
  irrecv. enableIRIn ();//starts the receiver

}
void gas_sensor()
{
  state=analogRead(smoke_sensor);
  if(analogRead(smoke_sensor)<sensorThres)// it reads the analog value at gas sensor and compares with sensor threshold value
  {
    digitalWrite(redLED,HIGH);
    delay(200);
    digitalWrite(redLED,LOW);
    delay(20);
    
  }
  if(analogRead(smoke_sensor)>sensorThres)
  {
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,HIGH);
  }
}



void loop() {
  
  if(irrecv. decode (&results))
  {
    if(1) // in this case we have assigned when high but you can assign any specific button here
    {
      if(state==LOW)
      {
        state=HIGH; // Button is pressed so is set to HIGH
        gas_sensor();
        digitalWrite(buzzer,HIGH);
        digitalWrite(fan,HIGH);
      }
      lastPressTime=millis();// millis returns back to number of miliseconds since the current program began to run
      }
      irrecv.resume();// will receive the next value
     }
     if(state==HIGH&&millis()-lastPressTime>MAX_TIME)
     {
      state=LOW;
      noTone(buzzer);
      
     }
}
 
    
    
  
  
