int led=9;
int buzzer=10;
const int IN1 = 6, IN3 = 4;
const int enable12 = 3;
double adcVoltage=0;
const int moisture=A0;
// Input state to rotate 2 motors CW
void Motor_Clockwise_operation()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH); 
}
// Input state to rotate 2 motors CCW
//Motor Brake
void Motor_off_operation()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(led, LOW);
  digitalWrite(buzzer,LOW);
  delay(5000);
}
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(enable12, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(moisture, INPUT);
  digitalWrite(enable12, HIGH); 
}

void loop()
{
  int value=analogRead(moisture);
  adcVoltage = moisture*(5/1024);
  if (adcVoltage>=2.123)
  {
  Motor_Clockwise_operation();
  }
  else
  {
   Motor_off_operation;
  } 
}
