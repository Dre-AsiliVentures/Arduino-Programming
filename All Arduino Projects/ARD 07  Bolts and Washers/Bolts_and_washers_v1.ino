
#include <LiquidCrystal.h>;
#include <Keypad.h>;
#define MaximumValue 999
int motorPin = 3;
int value=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
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
  
 
}
void loop {
  lcd.setCursor(2, 0);
  lcd.print("Input Digit");


  
  
  if (key != NO_KEY) // Do nothing if no key is pressed, incorporated from PaulS's example.
  {

  } if (Serial.available())// something entered in the keypad
  {
  isNumber();
  switch (value)
  case 100:
  analogWrite
  break;
  case 200:
  analogWrite
}

 
