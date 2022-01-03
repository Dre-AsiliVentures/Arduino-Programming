
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
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
void setup() {
  // put your setup code here, to run once:
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("WELCOME");
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
// Temperature loop
DHT.read11(dht_apin);
//lcd.setCursor(2,1);
//lcd.print("Humidity: ");
//delay(400);
//lcd.setCursor(2,11);
//lcd.print(DHT.humidity);
//lcd.setCursor(2,14);
//lcd.print("%  ");
//delay(400);
//project_name();
//lcd.setCursor(2,1);
//lcd.print("Temperature = ");
//lcd.print(DHT.temperature); 
//lcd.setCursor(2,14);
//lcd.println("C  ");
//delay(5000);//Wait 5 seconds before accessing sensor again.


// Measurement & Data Analysis
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

// Serial Monitor Output
 
// 1.LDR Measurement 
Serial.print("LDR Value:" );
Serial.print(ldr_value);
//Serial.print("Lux:" );
//Serial.print(lux);
Serial.print("\t"); // A vertical space indentation for the serial monitor
delay(400);

// 2. Moisture Measurement
Serial.print("Moisture: ");
Serial.print(moistureValue);
//lcd.setCursor(2,1);
//lcd.print("Moisture:");
//lcd.setCursor(2,9);
//lcd.print(sensorValue);
Serial.print("\t"); // A vertical space indentation for the serial monitor

// 3. Temperature and Humidity Measurement
Serial.print("DHT Temperature:" );
Serial.print(DHT.temperature);
Serial.print("\t"); // A vertical space indentation for the serial monitor
delay(100);
Serial.print("DHT Humidity: ");
Serial.print(DHT.humidity);

//ACTUATORS

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
