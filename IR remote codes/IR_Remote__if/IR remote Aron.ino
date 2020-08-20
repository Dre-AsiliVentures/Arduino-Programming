/*THIS CODE IS MANUFACTURED BY ARON &MWENDWA*/

# include <IRremote.h>
# define MAX_TIME 150 // max ms between codes
# define buzz 2
long lastPressTime = 0;
# define fan 4
int state = LOW;
# define led1 3
# define led2 4
//# define irrecv 11

IRrecv irrecv ( 11 );
decode_results results;


int statee=0;
# define motionsensor 5 


void motion_sensor()
{
  statee=digitalRead(motionsensor);
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

 pinMode(motionsensor,INPUT);
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
if (state == LOW) {
state = HIGH; // Button pressed, so set state to HIGH

digitalWrite (buzz, HIGH); 
digitalWrite(fan,HIGH);
delay(1000);
}
lastPressTime = millis(); /* MILLIS RETURN BACK NO MILISECONDS SINCE CURRENT PROGRAM BEGAN RUNNING*/
} 
irrecv. resume (); // Receive the next value
}
if (state == HIGH && millis() - lastPressTime > MAX_TIME)
{
state = LOW; // Haven't heard from the button for a while, so not pressed
digitalWrite (buzz, LOW); } 
}


