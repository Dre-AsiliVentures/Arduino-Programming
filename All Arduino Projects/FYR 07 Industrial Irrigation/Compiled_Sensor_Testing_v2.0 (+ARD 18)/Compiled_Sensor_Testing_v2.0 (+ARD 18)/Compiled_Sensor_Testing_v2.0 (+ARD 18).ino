/* Compiled Version 2.0 , FYR 07 and  ARD 18 Project 
 *  MQ-2 Gas sensor automation
 *  The code is manufactured by GreHiDeL
 *  
 */

// Liquid Crystal Display Pin connection
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);;
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
int blue_led=3;
int green_led=4;
//Moisture Parameters
#define Moisture_pin A3
int moistureValue;
void default_lcdprint()
{
lcd.clear();
lcd.setCursor(1,1);
lcd.print("FYR 07 & ARD 18");
}
void setup() {

// LCD Initialize commands
  // put your setup code here, to run once:
lcd.begin(20,4); //commence the 20 by 4 LCD display
Serial.begin(9600);
delay(500);//Delay to let system boot
Serial.println("DHT11 Humidity & temperature Sensor\n\n");
delay(1000);//Wait before accessing Sensor
pinMode(ldr_pin,INPUT); //Light Measurement PinMode
pinMode(dht_apin,INPUT); //Temperature Measurement PinMode
pinMode(Moisture_pin,INPUT);
pinMode(blue_led,OUTPUT);
pinMode(green_led,OUTPUT);
}
void loop() {
// ===========DHT11 MEASUREMENT ============
DHT.read11(dht_apin);
lcd.setCursor(1,2);
lcd.print("Humidity: ");
delay(400);
lcd.setCursor(12,2);
lcd.print(DHT.humidity);
lcd.setCursor(15,2);
lcd.print("%  ");
delay(400);
default_lcdprint());
lcd.setCursor(1,3);
lcd.print("Temperature = ");
lcd.setCursor(15,3);
lcd.print(DHT.temperature); 
lcd.setCursor(17,3);
lcd.print("%");
delay(100);
lcd.setCursor(18,3);
lcd.println("C");
/delay(500);
//Wait 5 seconds before accessing sensor again.

// ===================MEASUREMENT AND DATA ANALYSIS==================================================
//1. Light Measurement Value Reading and Data Analysis  
ldr_value=analogRead(ldr_pin);// Read the analog values from LDR pin & store in ldr_value variable
ldr_voltage=resolution*ldr_value; //Obtain the equivalent voltage using the 4.88mV/bit
resistor_voltage=vcc_voltage-ldr_voltage; //Substrate the ldr_voltage drop from the supply voltage to obtain the resistor voltage
ldr_resistance=(ldr_voltage*resistor_value)/resistor_voltage; //Current is the same since LDR and resistor are in series and V=IR so I=V/R
lux=500/ldr_resistance;
//Serial.print("\n"); //New line for the serial monitor
//lcd.setCursor(2,1);
//lcd.print("LDR VALUE: ");
//lcd.setCursor(2,12);
//lcd.print(ldr_value);
//By definition Lux =500/ LDR resistance

//2. Moisture  Measurement Value Reading and Data Analysis 
moistureValue=analogRead(Moisture_pin);

// ===================SERIAL MONITOR OUTPUT==================================================
 
// 1.LDR MEASUREMENT
Serial.print("LDR Value:" );
Serial.print(ldr_value);
//Serial.print("Lux:" );
//Serial.print(lux);
Serial.print("\t"); // A vertical space indentation for the serial monitor
delay(400);

// 2. MOISTURE MEASUREMENT
Serial.print("Moisture: ");
Serial.print(moistureValue);
//lcd.setCursor(2,1);
//lcd.print("Moisture:");
//lcd.setCursor(2,9);
//lcd.print(sensorValue);
Serial.print("\t"); // A vertical space indentation for the serial monitor

// 3. TEMPERATURE AND HUMIDITY MEASUREMENT
Serial.print("DHT Temperature:" );
Serial.print(DHT.temperature);
Serial.print("\t"); // A vertical space indentation for the serial monitor
delay(100);
Serial.print("DHT Humidity: ");
Serial.print(DHT.humidity);

//====================ACTUATORS===========================================

if(moistureValue>=600)
{
  digitalWrite(blue_led,HIGH);
  delay(1000);
  digitalWrite(blue_led,LOW);
  delay(500);
}
if(DHT.temperature!=0&&DHT.humidity!=0&&ldr_value!=0)
{
digitalWrite(green_led,HIGH);
delay(3000);

}

Serial.print("\n");
}