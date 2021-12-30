// This code is made by GreHiDeL M
// This code will print hello on the LCD as the basic test of LCD
/* 
 *  CONNECTIONS 
 *  RS----7          D5-----5        D6----4
 *  EN ---6          A------5V       D7----3
 *  D4----8          K------GND      RW----GND
 */
#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 8, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
}
void setup() {
  lcd.begin(16,4);
}

void loop() {
lcd.setCursor(0,0);
lcd.print("HELLO");
delay(800);
lcd.clear();

}
