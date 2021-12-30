int sound_sensor=3;
int redLed=4;
boolean ledState=false;
void setup() {
  // put your setup code here, to run once:
pinMode(sound_sensor,INPUT);
pinMode(redLed,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int soundSensor_data=digitalRead(sound_sensor);
  //if(soundSensor_data==1)
  //{
    if(ledState==false)
    {
      ledState=true;
      digitalWrite(redLed,HIGH);
    }
    else
    {
    ledState=false;
    digitalWrite(redLed,LOW);  
    }
//  }

}
