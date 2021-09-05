#include <RFID.h>
#define SDA 10
#define RST 9
RFID RC522(SDA,RST);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
RC522.init();
}

void loop() {
  // put your main code here, to run repeatedly:
if (RC522.isCard())
{
  RC522.readCardSerial();
  Serial.println("White card detected");
}
}
