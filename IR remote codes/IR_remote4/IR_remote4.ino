# include <IRremote.h>
# define MAX_TIME 150 // max ms between codes
# define LED_PIN 3
long lastPressTime = 0;
int state = LOW;
char button_value=0x1234;
IRrecv irrecv ( 11 );
decode_results results;
void setup () {
pinMode (LED_PIN, OUTPUT); // Status on pin 3 LED
irrecv. enableIRIn (); // Start the receiver
}
void loop () {
if (irrecv. decode (&results)) {
if ( results.value==button_value) 
{ // Can check for a specific button here
if (state == LOW) {
state = HIGH; // Button pressed, so set state to HIGH
digitalWrite (LED_PIN, HIGH); 
delay(1000);
}
lastPressTime = millis(); 
} 
irrecv. resume (); // Receive the next value
}
if (state == HIGH && millis() - lastPressTime > MAX_TIME) { state = LOW; // Haven't heard from the button for a while, so not pressed
digitalWrite (LED_PIN, LOW); } 
}


