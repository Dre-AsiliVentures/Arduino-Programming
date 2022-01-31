  //East lane pins
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27

void setup() {
//lcd.init();  
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("WYCLIFFE& RYAN");
}
void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("ENG. GEORGE");
delay(5000);
}
