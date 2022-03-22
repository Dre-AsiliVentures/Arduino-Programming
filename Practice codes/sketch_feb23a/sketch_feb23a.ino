int r1 = 8;
int y1 = 9;
int g1 = 10;
void setup() {
  // put your setup code here, to run once:
pinMode (r1, OUTPUT);
pinMode (y1, OUTPUT);
pinMode (g1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(r1,HIGH);
digitalWrite(y1,HIGH);
digitalWrite(g1,HIGH);
}
