#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
const int currentPin = A0;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
const int relay_grid = 3;
const int relay_solar = 4;
const int voltage_grid = 5;
const int voltage_solar = 6;
int GridSupplyState = digitalRead(voltage_grid);
int SolarSupplyState = digitalRead(voltage_solar);
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(relay_grid, OUTPUT);
  pinMode(relay_solar, OUTPUT);
  pinMode(voltage_grid, INPUT);
  pinMode(voltage_solar, INPUT);
}
void receivemessage() {
  mySerial.println("switching to solar");
}
void sendmessage() {
  mySerial.println("message from gsm");
  if (GridSupplyState == LOW && SolarSupplyState == LOW) {
    mySerial.println("BOTH ARE OFF");
  }
  else if (GridSupplyState == LOW && SolarSupplyState == HIGH) {
   
    delay(100);
    mySerial.println("SOLAR ON");
  }
  else if (GridSupplyState == HIGH && SolarSupplyState == LOW) {
    mySerial.println("GRID ON");
   
  }
  else {
    mySerial.println("BOTH ARE ON");
   
  }
}
void CurrentSensor()
{
  int adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1023.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  mySerial.println("Raw Sensor Value = " );
  mySerial.println(adcValue);
  delay(2000);

  mySerial.println("\t Voltage(mV) = ");
  mySerial.println(adcVoltage, 3);
  delay(2000);
  mySerial.println("\t Current = ");
  mySerial.println(currentValue, 3);
  delay(2500);
}
void loop(){
sendmessage();

  if (GridSupplyState == HIGH && SolarSupplyState == HIGH) {
    // turn Relay on:
   // CurrentSensor();
    digitalWrite(relay_grid, HIGH);
    digitalWrite(relay_solar, LOW);
    mySerial.println("BOTH ARE ON");
    delay(1000);
  } else if (GridSupplyState == HIGH && SolarSupplyState == LOW)
  {
    // turn Relay off:
    digitalWrite(relay_grid, HIGH);
    mySerial.println("GRID ON");
    digitalWrite(relay_solar, LOW);
    CurrentSensor();
    delay(1000);
  }
  else if (GridSupplyState == LOW && SolarSupplyState == HIGH)
  {
    receivemessage();
   // CurrentSensor();
    digitalWrite(relay_solar, HIGH);
    digitalWrite(relay_grid, LOW);
    delay(1000);
  }
  else
  {
    //CurrentSensor();
    digitalWrite(relay_solar,LOW);
    digitalWrite(relay_grid, LOW);
    mySerial.println("BOTH OFF");
    delay(1000);
  }

if (mySerial.available() > 0)
  switch (mySerial.read())
  {
    case 's':
      sendmessage();
      break;
      
  }
  }
