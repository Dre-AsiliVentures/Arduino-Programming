/*This code is manufactured by the Arduino Master
contact arduinomaster254@gmail.com
*/

/*The circuit:
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
 * wiper to LCD VO pin (pin 3*/
#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>
const int rs=12, en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int value=0;
int count=0;
int IR_sensor=10;
int solenoidPin=A5;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3' },
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int key = keypad.getKey();
int NumberCheck()//Function prototype to check if the entered digits are numbers
  {
  int isNumber;
  isNumber=(key>='0'&&key<='9');
  if(isNumber){
    value=value*10+key-'0';
    return value;
  }
  else
    return 0;
  
  }
void setup() {
  // put your setup code here, to run once:
pinMode(IR_sensor,INPUT);
pinMode(solenoidPin,OUTPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Enter a value");
}

void loop() {
  // put your main code here, to run repeatedly:
  int state=digitalRead(IR_sensor);
  int lastState;
  for (lastState=HIGH; state!=lastState,count=count++;){
    
  }

if (key != NO_KEY) // Do nothing if no key is pressed, incorporated from PaulS's example.
  {

  } if (Serial.available())// something entered in the keypad
  {
  NumberCheck();
  switch (value){
   case 100:
   int i=100;//variable for storing number of count within the value loop
   int bolts_counter=count;
   if(i==bolts_counter){//checks whether the box is full
    analogWrite(solenoidPin,HIGH);// if the box is full then activate the solenoid
    delay(2000);// wait for 2 seconds before terminating 
   }
   else   // if not full then solenoid remains in the present state.
   {
   analogWrite(solenoidPin,LOW);
   delay(2000);
   }
   break;
   }
  
  
  }
}
