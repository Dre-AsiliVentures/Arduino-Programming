/*This code controls three solenoids such that 
the sequence is Solenoid 1 then Solenoid2 then Solenoid 2
*/
int solenoid1=8; //This is the first Solenoid
int solenoid2=7; //This is the second solenoid
int solenoid3=6; //This is the third Solenoid
int sensor=10;    //This is the motion sensor

void setup() {
  // put your setup code here, to run once:
pinMode(solenoid1,OUTPUT); //Digital output device
pinMode(solenoid2,OUTPUT); //Digital output device
pinMode(solenoid3,OUTPUT); //Digital output device
pinMode(sensor,INPUT);     //Digital input device
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor_value=digitalRead(sensor); //Read the motion sensor's value
if (sensor_value==HIGH) // If there is motion
{
  digitalWrite(solenoid1,HIGH); //Turn on Solenoid1
  delay(5000);
  digitalWrite(solenoid1,LOW);//Retracts solenoid1
  digitalWrite(solenoid2,HIGH);
  delay(5000);
  digitalWrite(solenoid2,LOW);//Retracts solenoid1
  digitalWrite(solenoid3,HIGH); //Extends solenoid3
  delay(5000);
  digitalWrite(solenoid3,LOW);
  delay(2000);
  
  
}
else
{
  digitalWrite(solenoid1,LOW);
  digitalWrite(solenoid2,LOW);
  digitalWrite(solenoid3,LOW);
}
}
