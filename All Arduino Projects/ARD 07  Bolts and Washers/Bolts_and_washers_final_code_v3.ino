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
int value,i,q;
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
const char count_default[3]={'1','0','0'};
const char attempt[3]={0,0,0};
int key = keypad.getKey();
int z=0;
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
 void checkCount()
 {
  for(i=0;i<3;i++){// loop until user enters three digits
    if(attempt[q]==count_default[q])// check if entered value equal to 100
    {
      //activate solenoid
    analogWrite(solenoidPin,HIGH);// if the box is full then activate the solenoid
    delay(2000);// wait for 2 seconds before terminating 
    }
    else{
    analogWrite(solenoidPin,LOW);
   delay(2000);
    }
  }
 }
 
void setup() {
  // put your setup code here, to run once:
pinMode(IR_sensor,INPUT);
for(int row=0;row<ROWS;row++)
{
  pinMode(rowPins[row],INPUT);
}
for(int cols=0;cols<COLS;cols++)
{
  pinMode(colPins[cols],INPUT);
}
pinMode(solenoidPin,OUTPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Enter a value");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print(key);
  int state=digitalRead(IR_sensor);
  while(state!=HIGH){
    count=count++;
  }
if (key != NO_KEY) // Do nothing if no key is pressed, incorporated from PaulS's example.
  {

  } if (Serial.available())// something entered in the keypad
  {
  NumberCheck();
  switch(keypad.getState())
  {
    default:
    //attempt[z]=key;
    case PRESSED:
    switch(key)
    {
      case '*':
      value=0;
      lcd.clear();
      break;
      case'#':
      value=key;
      break;
      }
      case HOLD:
      if(key=='*')
      {
        value=0;
        lcd.clear();
      }
  }
  while(value!=0)//loop if the entered values are digits
  {
    checkCount();
  }
  
}
}
