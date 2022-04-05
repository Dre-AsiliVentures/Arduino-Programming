#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Create the lcd object at 
//Temperature measurement
#include <dht.h>
#define dht_apin A2 // Analog Pin sensor is connected to
dht DHT;
//LDR Parameters
#define vcc_voltage 5 // VCC voltage 
#define ldr_pin A0  // Pin connected to the LDR 
#define resolution 0.004887 // 4.88mV/bit from 5V divided by 1023 bits
#define resistor_value 10000 //10kiloOhm resistance in series with the LDR
int ldr_voltage;
int ldr_resistance;
int resistor_voltage; //Voltage drop across the resistor
float ldr_value; //for storing the LDR analog value
int lux;
//Moisture Parameters
#define Moisture_pin A3
int sensorValue;
void default_display()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("FYR 07 TESTING");
}
void setup() {
  // put your setup code here, to run once:
lcd.begin();
Serial.begin(9600);
delay(500);//Delay to let system boot
pinMode(ldr_pin,INPUT); //Light Measurement PinMode
pinMode(dht_apin,INPUT); //Temperature Measurement PinMode
pinMode(Moisture_pin,INPUT);
default_display();

delay(5000);
}
void loop() {
// Humidity  loop
DHT.read11(dht_apin);
Serial.print(DHT.humidity); //Serial.print("Current humidity = ");
//Serial.print("%  ");
lcd.setCursor(0,1);
lcd.print("Humidity: ");
lcd.setCursor(11,1);
lcd.print(DHT.humidity);// DHT Humidity print on the LCD
delay(2000);
default_display();
Serial.print(","); //comma seperated delimiter
// Temperature  loop
Serial.print(DHT.temperature); //Serial.print("temperature = ");
//Serial.println("C  ");
lcd.setCursor(0,1);
lcd.print("Temp: ");
lcd.setCursor(7,1);
lcd.print(DHT.temperature);// DHT Humidity print on the LCD
delay(2000);
//lcd.print("\xe2\x84\x83");// DHT Temperature print on the LCD
default_display();
//Moisture Measurement Loop
Serial.print(","); //Comma Seperated Delimiter
sensorValue=analogRead(Moisture_pin); 
Serial.print(sensorValue); //Serial.print("Moisture value: ");
delay(2000);
lcd.setCursor(0,1);
lcd.print("Moisture: ");
lcd.setCursor(11,1);
lcd.print(sensorValue);
delay(2000);
default_display();
Serial.print(","); //Comma Seperated Delimiter
//Light Measurement loop  
ldr_value=analogRead(ldr_pin);// Read the analog values from LDR pin & store in ldr_value variable
ldr_voltage=resolution*ldr_value; //Obtain the equivalent voltage using the 4.88mV/bit
resistor_voltage=vcc_voltage-ldr_voltage; //Substrate the ldr_voltage drop from the supply voltage to obtain the resistor voltage
ldr_resistance=(ldr_voltage*resistor_value)/resistor_voltage; //Current is the same since LDR and resistor are in series and V=IR so I=V/R
lux=500/ldr_resistance;
lcd.setCursor(0,1);
lcd.print("LDR Value: ");
lcd.setCursor(12,1);
lcd.print(ldr_value);
delay(2000);
default_display();
Serial.print(ldr_value); //Serial.print("LDR VALUE: ");
Serial.print(","); //Comma Seperated Delimiter
Serial.print(ldr_resistance); //Serial.print("\t LDR Resistance");
Serial.print(","); //Comma Seperated Delimiter
Serial.print(ldr_voltage);
Serial.print(","); //Comma Seperated Delimiter
 //By definition Lux =500/ LDR resistance
lux=500/ldr_resistance;
lcd.setCursor(0,1);
lcd.print("LUX Value: ");
lcd.setCursor(12,1);
lcd.print(lux);
delay(2000);
default_display();
//Serial.println(lux);
delay(900);
}
