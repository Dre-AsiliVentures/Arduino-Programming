int led=7;
int sound_sensor=A5;
float sound_value;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(sound_sensor,INPUT);
Serial.begin(9600);
//pinMode(led,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
sound_value=analogRead(sound_sensor);
Serial.println(sound_value);
delay(20);
if(sound_value>=25)
{
  digitalWrite(led,HIGH);
}
if(sound_value<25)
{
  digitalWrite(led,LOW);
}
}
