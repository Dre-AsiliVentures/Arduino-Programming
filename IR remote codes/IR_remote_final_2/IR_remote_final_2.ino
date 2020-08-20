/*THIS CODE IS MANUFACTURED BY ARON &MWENDWA*/

# include <IRremote.h>
# define MAX_TIME 150 // max ms between codes
# define REMOTE_LED_PIN 3
long lastPressTime = 0;
# define redLED 9
# define greenLED 6
# define buzzer 7
# define fan 8
# define MAX_TIME 150
# define smoke_sensor A5
int sensorThres=170;


int state = LOW;
IRrecv irrecv ( 11 );
decode_results results;
void setup () {
pinMode (REMOTE_LED_PIN, OUTPUT); // Status on pin 3 LED,his is the LED which will blink when remote is pressed.
irrecv. enableIRIn (); // Start the  IR receiver
pinMode(smoke_sensor,INPUT);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
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
    tone(buzzer,1000,200);


if (irrecv. decode (&results))
{
if ( 1 )//In our case 1 means that it is high Can check for a specific button here 
{
if (state == LOW) {
state = HIGH; // Button pressed, so set state to HIGH
digitalWrite (REMOTE_LED_PIN, HIGH); 
delay(1000);
//gas_sensor();
digitalWrite(buzzer,HIGH);
digitalWrite(fan,HIGH);
}
lastPressTime = millis(); /* MILLIS RETURN BACK NO MILISECONDS SINCE CURRENT PROGRAM BEGAN RUNNING*/
} 
irrecv. resume (); // Receive the next value
}
if (state == HIGH && millis() - lastPressTime > MAX_TIME)
{
state = LOW; // Haven't heard from the button for a while, so not pressed
digitalWrite (REMOTE_LED_PIN, LOW); } 
}

  if(analogRead(smoke_sensor)>sensorThres)
  {
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,HIGH);
    noTone(buzzer);
   digitalWrite(fan,LOW);
  }
}


void loop () {
 gas_sensor();

}

