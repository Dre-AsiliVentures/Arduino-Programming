//Bluetooth Module Control HC10 Testing
char Incoming_Value=0;
int LED_Blue=8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//Serial.println("THE SYSTEM IS STARTING");
pinMode(LED_Blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  Incoming_Value=Serial.read();
  Serial.print(Incoming_Value);
  Serial.print("\n");
  if(Incoming_Value=='1')
  {
    digitalWrite(LED_Blue,HIGH);
  }
  if(Incoming_Value=='0')
  {
    digitalWrite(LED_Blue,LOW);
  }
  
}
}
