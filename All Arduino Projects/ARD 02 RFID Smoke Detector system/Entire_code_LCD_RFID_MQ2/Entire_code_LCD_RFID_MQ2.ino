// This code is made by GreHiDeL M
// This is the entire  final code for arduino MQ-2 GAS SENSOR PROJECT
// This code is customised for a 16x4 LCD only.
//For a 16x2 LCD you will have to change setCursor values.
#include <SPI.h>
#include <RFID.h>
#include <LiquidCrystal.h>
#define SDA_DIO 10
#define RESET_DIO 9
RFID RC522(SDA_DIO, RESET_DIO); 

//int outPin = 7;
/* Create an instance of the RFID library */

////#define lightPin A0
const int rs = 7, en = 6, d4 = 8, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int threshold=60;
int state = 0;
int buzzer=2;
int fan= A3;
//int rfid_pin =2;
int gas_sensorpin=A5;
int led1=A4;
int led2=A2;

void rfid_circuit()// is a funtion prototype
{
  if (RC522.isCard() )
 {
    Serial.println();
    /* If so then get its serial number */
   RC522.readCardSerial();
  Serial.println("Card detected!");
  lcd.setCursor(2,1);
lcd.print("Card detected ");
delay(200);
lcd.clear();
digitalWrite(buzzer,LOW);
delay(200);
 digitalWrite(fan,LOW);
}
  else{
 digitalWrite(buzzer,HIGH);
 digitalWrite(fan,HIGH);
 lcd.setCursor(0,1);
lcd.print("PLACE CARD ");
// requires a card to deactiate buzzer and fan
  }
 }
void setup() {
  lcd.begin(16,4);
  Serial.begin(9600);
  pinMode(gas_sensorpin,INPUT);
  SPI.begin(); /* Enable the SPI interface */
  RC522.init(); /* Initialise the RFID reader */
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
  //pinMode(rfid_pin,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
 }

void loop() {
lcd.setCursor(0,0);
lcd.print("GAS STATE IS:");
state=analogRead(gas_sensorpin);
lcd.setCursor(16,0);
lcd.print(state); 
Serial.println(state);
if(state>=threshold)
{
//digitalWrite(rfid_pin,HIGH);
  digitalWrite(led1,HIGH);
  lcd.setCursor(4,3);
lcd.print("SMOKE  DETECTED!!!");
rfid_circuit();
}
if(state<threshold)
{
   digitalWrite(led2,HIGH);
  digitalWrite(fan,LOW);
  digitalWrite(buzzer,LOW);
 lcd.setCursor(4,3 );
lcd.print("NO SMOKE AROUND");
}
}// end of the code



