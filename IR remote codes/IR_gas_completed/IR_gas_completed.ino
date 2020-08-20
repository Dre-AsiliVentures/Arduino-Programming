#include <LiquidCrystal.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#define redLED 12
# define greenLED 4
# define buzzer 10
# define fan 6
# define MAX_TIME 150
# define smoke_sensor A5
# define remote_pin 6
int sensorThres=134;
long lastPressTime =0;
int state;
int Gas_state;
IRrecv irrecv (11);
decode_results results;
LiquidCrystal lcd (8,2,9,5,3,7);
void remote_function(){
  if (irrecv. decode (&results))
{
if ( 1 )//In our case 1 means that it is high Can check for a specific button here 
{
if (state == LOW) {
state = HIGH; // Button pressed, so set state to HIGH
digitalWrite (redLED, HIGH);
digitalWrite(fan,HIGH);
digitalWrite(buzzer,HIGH);

}
lastPressTime = millis(); /* MILLIS RETURN BACK NO MILISECONDS SINCE CURRENT PROGRAM BEGAN RUNNING*/
} 
irrecv. resume (); // Receive the next value
}
//if (state == HIGH && millis() - lastPressTime > MAX_TIME)
//{
//state = LOW; // Haven't heard from the button for a while, so not pressed
//digitalWrite (REMOTE_LED_PIN, LOW);
}
void setup()
{
  pinMode(smoke_sensor,INPUT);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
  Serial.begin(9600);
  irrecv. enableIRIn ();
  lcd.begin(16,2);
}
void loop(){
//digitalWrite(greenLED,HIGH);
//digitalWrite(redLED,LOW);
//digitalWrite(buzzer,LOW);
//digitalWrite(fan,LOW);
//digitalWrite(remote_pin,LOW);
Gas_state=analogRead(smoke_sensor);
Serial.print("A5:");
Serial.println(Gas_state);
if(analogRead(smoke_sensor)>=sensorThres)
{
  digitalWrite(redLED,HIGH);
  //digitalWrite(greenLED,LOW);
  digitalWrite(remote_pin,HIGH);
  lcd.setCursor(0,1);
  lcd.print("SMOKE PRESENT");
  remote_function();
}
if(analogRead(smoke_sensor)<sensorThres)
{
digitalWrite(greenLED,HIGH);
digitalWrite(redLED,LOW);
digitalWrite(buzzer,LOW);
digitalWrite(fan,LOW);
digitalWrite(remote_pin,LOW);
lcd.setCursor(0,1);
lcd.print("NO SMOKE"); 
}
//delay(100);

}

