/* This code works with Sim800L and a push button
 * Press the button to send a simple SMS/Text to a specified phone number
 * Refer to the 'Electronics Dr' for more details 
 */
#include <SoftwareSerial.h>
SoftwareSerial sim800c(2, 3); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted
#define button 7 //Button pin, on the other pin it's wired with GND

bool button_State; //Button state
void setup()
{
 
  pinMode(button, INPUT); //The button is always on HIGH level, when pressed it goes LOW
  sim800c.begin(9600);   //Module baude rate, this is on max, it depends on the version
  Serial.begin(9600);   
  delay(1000);
}
 
void loop()
{
  button_State = digitalRead(button);   //We are constantly reading the button State
 
  if (button_State == HIGH) {            //And if it's pressed
    Serial.println("Button pressed");   //Shows this message on the serial monitor
    delay(200);                         //Small delay to avoid detecting the button press many times
    
    SendSMS();                          //And this function is called

 }
 
  if (sim800c.available()){            //Displays on the serial monitor if there's a communication from the module
    Serial.write(sim800c.read()); 
  }
}
 
void SendSMS()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800c.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800c.print("AT+CMGS=\"+*********\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800c.print("Congratulations, A prize has been WON");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800c.print((char)26);// (required according to the datasheet)
  delay(500);
  

}
