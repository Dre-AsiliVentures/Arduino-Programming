/*
 *  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
#include <LiquidCrystal.h>
#include <IRremote.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int RECV_PIN = 7;
int greenled=8;
int redled=9;
int fan=13;
int buzzer=10;
int gas_sensor=A1;
int gas_vcc=14;
int state=0;
int threshold=60;
IRrecv irrecv(RECV_PIN);
decode_results results;
//char val=results.value;
void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(greenled,OUTPUT);
  pinMode(redled,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(gas_vcc,OUTPUT);
  pinMode(gas_sensor,INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("GreHiDeL");
}

void loop() {
  if (irrecv.decode(&results))
  {
    switch(results.value)
    {
      case 0xFFB04F:// when the power button of remote is switched ON
      digitalWrite(gas_vcc,HIGH);
      if(state<threshold)// when the gas sensor detects a normal surrounding
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("No smoke detected");
       digitalWrite(greenled,HIGH);
       digitalWrite(redled,LOW);
       digitalWrite(buzzer,LOW);
       digitalWrite(fan,LOW);
      }
      if (state>=threshold);
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Smoke detected");
        digitalWrite(greenled,LOW);
        digitalWrite(redled,HIGH);
        delay(200);
        digitalWrite(redled,LOW);
        delay(100);
        digitalWrite(buzzer,HIGH);
        digitalWrite(fan,HIGH);
        switch(results.value)
        {
           case 0xFFA563:// when an override button is pressed to switch off the buzzer and fan
           digitalWrite(buzzer,LOW);
           digitalWrite(fan,LOW);
        }
       
      }
      
    }
       switch(results.value)
    {
      case 0xFFA857:// when power button of remote is switched off
      digitalWrite(gas_vcc,LOW);
      
    }
    irrecv.resume();
  }
  
  delay(100);
}//the end

