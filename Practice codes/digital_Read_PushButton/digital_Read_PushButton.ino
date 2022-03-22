// Note the pull-up and Pull-down concepts
int push_button=9;
int led=8;
bool state=0;
void setup() {
  // put your setup code here, to run once:
pinMode(push_button,INPUT);
pinMode(led,OUTPUT);
digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
state=digitalRead(push_button);
if (state==HIGH)
{
  digitalWrite(led,HIGH);
}
else
{
  digitalWrite(led,LOW);
}
}
