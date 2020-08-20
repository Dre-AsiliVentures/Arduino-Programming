int Green_LED=8;
int Yellow_LED=7;
int Orange_LED=5;
int Blue_LED=3;
int Red_LED=1;
int Photodiode=A0;
int val = analogRead(Photodiode);   
float analogvalue=val/10; 
 
void setup()
{
 for (int i = 1; i <=13; i++) { 
    pinMode(i, OUTPUT);
 }
  pinMode(Photodiode,INPUT);
}

void loop()
{
 for (int x = 2; x <= analogvalue; x++) 
 {  
    digitalWrite(x, HIGH);
  }
  for (int y = 13; y >= analogvalue; y--) { 
    digitalWrite(y, LOW);
  
}
}
