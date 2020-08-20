int Green_LED=8;
int Yellow_LED=7;
int Orange_LED=5;
int Blue_LED=3;
int Red_LED=1;
int Photodiode=A0;
int x;
void setup()
{
 for (int i = 1; i <=13; i++) { 
    pinMode(i, OUTPUT);
 }
  pinMode(Photodiode,INPUT);
}

void loop()
{
 int voltage =analogRead(A0);
 float input= voltage*(5/1023);
 for (x=0; x<=input; x++)
 {
   digitalWrite(x,HIGH);
  
}
  for(x=13;x<=input; x--)
  {
    digitalWrite(x,LOW);
}
}
  
