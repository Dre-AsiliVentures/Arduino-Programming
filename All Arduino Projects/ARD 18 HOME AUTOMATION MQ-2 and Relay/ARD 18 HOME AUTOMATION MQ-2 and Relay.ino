/* This is an automation Home project that controls the fan using the Gas state values
Code written by GreHiDeL MwEnDwA
Future version of this project: Inclusion of IR support working with the Extension box
*/
int extension_relay=4;
int fan_motor=5;
int mq2_gas_sensor=A1;
float current_gas_stateValue;

void setup() {
  // put your setup code here, to run once:
pinMode(extension_relay,OUTPUT);
pinMode(fan_motor,OUTPUT);
pinMode(mq2_gas_sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
current_gas_stateValue=analogRead(mq2_gas_sensor);
if (current_gas_stateValue>=300)
{
  digitalWrite(fan_motor,HIGH);
}
digitalWrite(extension_relay,HIGH);

digitalWrite(mq2_gas_sensor,HIGH);
}
