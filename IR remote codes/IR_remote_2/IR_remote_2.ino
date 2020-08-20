/*THIS CODE IS MANUFACTURED BY ARON &MWENDWA*/

# include <IRremote.h>
# define MAX_TIME 150 // max ms between codes
# define REMOTE_LED_PIN 12
long lastPressTime = 0;
int state = LOW;
IRrecv irrecv ( 11 );
decode_results results;
void setup () {
pinMode (REMOTE_LED_PIN, OUTPUT); // Status on pin 3 LED,his is the LED which will blink when remote is pressed.
irrecv. enableIRIn (); // Start the  IR receiver
digitalWrite(6,HIGH);
}
void loop () {
if (irrecv. decode (&results))
{
if ( 1 )//In our case 1 means that it is high Can check for a specific button here 
{
if (state == LOW) {
state = HIGH; // Button pressed, so set state to HIGH
//digitalWrite (REMOTE_LED_PIN, HIGH); 
//delay(1000);
}
lastPressTime = millis(); /* MILLIS RETURN BACK NO MILISECONDS SINCE CURRENT PROGRAM BEGAN RUNNING*/
} 
irrecv. resume (); // Receive the next value
}
if (state == HIGH && millis() - lastPressTime > MAX_TIME)
{
state = LOW; // Haven't heard from the button for a while, so not pressed
digitalWrite (REMOTE_LED_PIN, HIGH); } 
}


