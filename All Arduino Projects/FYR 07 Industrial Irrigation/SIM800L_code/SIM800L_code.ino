#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  
}
void sendMessage()
{
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  mySerial.println("AT+CMGS=\"+254747958381\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  mySerial.print("Last Minute Engineers | lastminuteengineers.com"); //text content
  mySerial.write(26);
}
void loop()
{
  sendMessage();
  delay(100);
  Serial.println("Nmetuma message Daktari");
}


 
