#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


# define redLED 12
# define greenLED 4
# define buzzer 10
# define fan 6
# define smoke_sensor A5
int sensorThres=170;
long lastPressTime=0;
int state;
IRrecv irrecv ( 11 );
decode_results results;
void gas_sensor()
{
  state=analogRead(smoke_sensor);
  if(analogRead(smoke_sensor)>sensorThres)// it reads the analog value at gas sensor and compares with sensor threshold value
  {
    digitalWrite(redLED,HIGH);
    delay(200);
    digitalWrite(redLED,LOW);
    delay(20);
    
  }
  if(analogRead(smoke_sensor)<sensorThres)
  {
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,LOW);
  }
}



void setup () {
  
 pinMode(smoke_sensor,INPUT);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);  
//pinMode (REMOTE_LED_PIN, OUTPUT); // Status on pin 3 LED,his is the LED which will blink when remote is pressed.
irrecv. enableIRIn (); // Start the  IR receiver
}

void loop() {
  // put your main code here, to run repeatedly:
gas_sensor();
if (irrecv. decode (&results))
{
if ( 1 )//In our case 1 means that it is high Can check for a specific button here 
{
if (state == LOW) {
state = HIGH; // Button pressed, so set state to HIGH
digitalWrite (redLED, HIGH); 
delay(1000);
}
lastPressTime = millis(); /* MILLIS RETURN BACK NO MILISECONDS SINCE CURRENT PROGRAM BEGAN RUNNING*/
} 
irrecv. resume (); // Receive the next value
}
if (state == HIGH && millis() - lastPressTime > MAX_TIME)
{
state = LOW; // Haven't heard from the button for a while, so not pressed
digitalWrite (redLED, LOW); } 
}


