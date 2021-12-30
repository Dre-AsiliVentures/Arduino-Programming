#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);
const int currentPin = A0;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
 // set pin numbers:
const int MainsSupplyPin = A0;     // the number of the pushbutton pin
const int RelayPin3 =  3;      // the number of the Relay pin
const int RelayPin4 =  4;
const int GenSwitchPin5 =  A1;
// variables will change:
int MainsSupplyState = 0;         // variable for reading the MainsSupplybutton status
int GenSwitchState = 0;         // variable for reading the GenSwitchbutton status

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(100);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+25490769801\"\r"); // Replace x with mobile number
  delay(100);
  mySerial.println("I am SMS from GSM Module");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
 void RecieveMessage()
{
  mySerial.println("hello");
  delay(100);
  CurrentSensor();
  delay(100);
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
 void CurrentSensor()
{
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  mySerial.println("Raw Sensor Value = " );
  mySerial.println(adcValue);
  delay(2000);

  mySerial.println("\t Voltage(mV) = ");
  mySerial.println(adcVoltage,3);
  delay(2000); 
  mySerial.println("\t Current = ");
  mySerial.println(currentValue,3);
  delay(2500);
}
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  // initialize the Relay pin3 as an output:
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(MainsSupplyPin, INPUT);
  pinMode(GenSwitchPin5, INPUT);
}
void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
 {
   Serial.write(mySerial.read());
 }
  // read the state of the pushbutton value:
  MainsSupplyState = digitalRead(MainsSupplyPin);
  GenSwitchState=digitalRead(GenSwitchPin5);
  // check if the MainsSupplybutton is pressed.
  // if it is, the MainsSupplyState is HIGH:
  if (MainsSupplyState == HIGH && GenSwitchState==HIGH) {
    // turn Relay on:
    digitalWrite(RelayPin4, LOW);
    digitalWrite(RelayPin3, HIGH);
    delay(1000);
  } else if (MainsSupplyState == HIGH && GenSwitchState==LOW) 
  {
    // turn Relay off:
    digitalWrite(RelayPin3, HIGH);
    digitalWrite(RelayPin4, LOW);
    delay(1000);
  } 
  else if (MainsSupplyState == LOW && GenSwitchState==HIGH)
  {
    //
    digitalWrite(RelayPin3, LOW);
    digitalWrite(RelayPin4, HIGH);
    delay(1000);
    }
    else
    {
    digitalWrite(RelayPin3, LOW);
    digitalWrite(RelayPin4, LOW);
    delay(1000);
    }
}


 
