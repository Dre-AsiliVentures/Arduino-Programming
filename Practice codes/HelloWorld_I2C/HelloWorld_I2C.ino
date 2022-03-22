//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("FYR 02 FINAL YEAR") ;
  lcd.setCursor(5,1);
  lcd.print("PROJECT");
//  lcd.setCursor(2,1);
//  lcd.print("");
//   lcd.setCursor(0,2);
//  lcd.print("Arduino LCM IIC 2004");
//   lcd.setCursor(2,3);
//  lcd.print("Power By Ec-yuan!");
}


void loop()
{
}
