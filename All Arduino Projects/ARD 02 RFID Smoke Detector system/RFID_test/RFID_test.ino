// This code is made by GreHiDeL M
// This code will print to the serial monitor when a white card 
// is detected
// CONNECTIONS SDA---PIN 10, RST--9
#include <SPI.h>
#include <RFID.h>
#define SDA_DIO 10
// Defines the Serial Data SDA pin to be pin 10
#define RESET_DIO 9
// Defines the reset pin RST pin 9 to be pin 9
RFID RC522(SDA_DIO, RESET_DIO); 


void setup() {
  
  Serial.begin(9600);// begins the serial monitor at 9600
  SPI.begin(); /* Enable the SPI interface */
  RC522.init();/* Initialise the RFID reader */
  }

void loop() {
 if (RC522.isCard() )
 {
    Serial.println();
    /* If so then get its serial number */
   RC522.readCardSerial();
  Serial.println(" A white card detected!");
  // the above string will be printed in the serial moonitor when a card
  // is detected.
  }
 }
// ------- End of the code-----------------------
