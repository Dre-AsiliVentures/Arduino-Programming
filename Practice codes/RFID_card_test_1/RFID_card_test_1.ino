#include <RFID.h>
int SDA_pin=10;
int RESET_pin=9;
RFID RC522_chip(SDA_pin,RESET_pin);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
RC522_chip.init();
}

void loop() {
  // put your main code here, to run repeatedly:
if (RC522_chip.isCard())
{
  RC522_chip.readCardSerial();
  Serial.println("White Card detected");
}
}
