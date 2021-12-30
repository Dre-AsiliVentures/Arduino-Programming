#include <SoftwareSerial.h>
const int Button = 8;
SoftwareSerial mySerial(9, 10);// RX and TX pins of the Arduino

void SendMessage()//function prototype
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("I am SMS from GSM Module");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  pinMode(Button, INPUT);
}


void loop()
{
  int stateButton = digitalRead(Button);
  if (Serial.available()>0)
   {
    if(stateButton == 1) {
      SendMessage();
    }
    if (mySerial.available()>0){
   Serial.write(mySerial.read());
}
   
   }
   }
   
 

 

 
