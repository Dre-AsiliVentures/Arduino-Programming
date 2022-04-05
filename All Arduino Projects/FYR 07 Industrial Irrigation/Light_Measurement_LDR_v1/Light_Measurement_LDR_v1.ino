#define vcc_voltage 5 // VCC voltage 
#define ldr_pin A6  // Pin connected to the LDR 
#define resolution 0.004887 // 4.88mV/bit from 5V divided by 1023 bits
#define resistor_value 1000 //1kiloOhm resistance in series with the LDR
int ldr_voltage;
int ldr_resistance;
int resistor_voltage; //Voltage drop across the resistor
float ldr_value; //for storing the LDR analog value
int lux;
void setup() {
  // put your setup code here, to run once:
  pinMode(ldr_pin,INPUT);// Declare the LDR connected pin as an input 
  Serial.begin(9600);
  Serial.println("Welcome Daktari");
}
void loop() {
  // put your main code here, to run repeatedly:
ldr_value=analogRead(ldr_pin);// Read the analog values from LDR pin & store in ldr_value variable
ldr_voltage=resolution*ldr_value; //Obtain the equivalent voltage using the 4.88mV/bit
resistor_voltage=vcc_voltage-ldr_voltage; //Substrate the ldr_voltage drop from the supply voltage to obtain the resistor voltage
ldr_resistance=(ldr_voltage*resistor_value)/resistor_voltage; //Current is the same since LDR and resistor are in series and V=IR so I=V/R
lux=500/ldr_resistance;
Serial.print("LDR VALUE: ");
Serial.print(ldr_value);
Serial.print("\t LDR Resistance");
Serial.print(ldr_resistance);
Serial.print("\t LDR Voltage:");
Serial.print(ldr_voltage);
 //By definition Lux =500/ LDR resistance
Serial.println("\n");
//Serial.println(lux);
delay(400);
}
