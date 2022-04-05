#include <dht.h>
#define dht_apin A6 // Analog Pin sensor is connected to
dht DHT;
#define vcc_voltage 5 // VCC voltage 
#define ldr_pin A5  // Pin connected to the LDR 
#define resolution 0.004887 // 4.88mV/bit from 5V divided by 1023 bits
#define resistor_value 1000 //1kiloOhm resistance in series with the LDR
int ldr_voltage;
int ldr_resistance;
int resistor_voltage; //Voltage drop across the resistor
float ldr_value; //for storing the LDR analog value
int lux;
void temperature_measurement()
{
  //Start of Program 
    DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    delay(5000);//Wait 5 seconds before accessing sensor again.
  //Fastest should be once every two seconds.
}
void ldr_measurement()
{
  ldr_value=analogRead(ldr_pin);// Read the analog values from LDR pin & store in ldr_value variable
ldr_voltage=resolution*ldr_value; //Obtain the equivalent voltage using the 4.88mV/bit
resistor_voltage=vcc_voltage-ldr_voltage; //Substrate the ldr_voltage drop from the supply voltage to obtain the resistor voltage
ldr_resistance=(ldr_voltage*resistor_value)/resistor_voltage; //Current is the same since LDR and resistor are in series and V=IR so I=V/R
lux=500/ldr_resistance;
Serial.print("LDR VALUE: ");
Serial.print(ldr_value);
Serial.print("\t LDR Resistance: ");
Serial.print(ldr_resistance);
Serial.print("\t LDR Voltage:");
Serial.print(ldr_voltage);
 //By definition Lux =500/ LDR resistance
Serial.println("\n");
//Serial.println(lux);
delay(400);
}
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(ldr_pin,INPUT);// Declare the LDR connected pin as an input 
  Serial.println("Welcome Daktari");
}//end "setup()"
void loop(){
  temperature_measurement();
  ldr_measurement();
}// end loop(
