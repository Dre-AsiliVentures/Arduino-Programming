/*
Code adapted from the Wire Library 
Reference made to https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/
This is a unique code for scanning I2C devices using the Wire Library
Author: Andrew Mwendwa -The ElectronicsDr
*/
#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  while(!Serial)
{

}
Serial.println();
Serial.println("The I2C scanner currently running");
byte count =0;
for (byte i=8;i<120;i++)
{
Wire.beginTransmission(i);
if(Wire.endTransmission()==0)
{
  Serial.print("An Address found:" );
  Serial.print(i,DEC);
  Serial.print(" (0x");  
  Serial.print(i,HEX);
  Serial.println(")");
  count++;
  delay(1); // Un-necessary delay
       }
}       
 // End of I2C search 
Serial.println("The system is done");
Serial.print("Found ");
Serial.print(count,DEC); 
Serial.println(" device(s). ");
}
void loop()
{
}// End of void loop
