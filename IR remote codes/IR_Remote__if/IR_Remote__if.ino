#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

/*THIS CODE IS MANUFACTURED BY ARON &MWENDWA*/


# define MAX_TIME 150 // max ms between codes
# define buzz 2
long lastPressTime = 0;
# define fan 4
# define smokeSensor A5
//int state = LOW;
# define led1 12
# define led2 10
//# define irrecv 11

IRrecv irrecv ( 11 );
decode_results results;


int statee=0;



void gas_sensor()
{
  statee=analogRead(smokeSensor);
  if(statee==HIGH){
digitalWrite(led2,HIGH);
digitalWrite(led1,LOW);
//digitalWrite(irrecv,HIGH);
  }
  if (statee==LOW)
  {
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
    
  }

}

void setup () {

 pinMode(smokeSensor,INPUT);
pinMode (led1, OUTPUT);
 pinMode (led2, OUTPUT);
pinMode (buzz, OUTPUT); // Status on pin 3 LED,his is the LED which will blink when remote is pressed.
irrecv. enableIRIn (); // Start the  IR receiver
}
void loop () {


 motion_sensor(); 
if (irrecv. decode (&results))
{
if ( 1 )//In our case 1 means that it is high Can check for a specific button here 
{
if (statee == LOW) {
statee = HIGH; // Button pressed, so set state to HIGH

digitalWrite (buzz, HIGH); 
digitalWrite(fan,HIGH);
delay(1000);
}
lastPressTime = millis(); /* MILLIS RETURN BACK NO MILISECONDS SINCE CURRENT PROGRAM BEGAN RUNNING*/
} 
irrecv. resume (); // Receive the next value
}
if (statee == HIGH && millis() - lastPressTime > MAX_TIME)
{
statee = LOW; // Haven't heard from the button for a while, so not pressed
digitalWrite (buzz, LOW); } 
}


