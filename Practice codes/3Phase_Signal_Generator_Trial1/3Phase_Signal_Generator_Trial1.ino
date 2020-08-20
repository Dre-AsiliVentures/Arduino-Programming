void setup() {
// initialize digital pin 13,12&8 as an output.
pinMode(13, OUTPUT);
pinMode(12,OUTPUT);
pinMode(8,OUTPUT);
}
void loop() {
int var=0;
digitalWrite(13, HIGH);
digitalWrite(8,LOW);
digitalWrite(12,LOW);
delay(6.67);
digitalWrite(12,HIGH);
while(var==0){
delay(3.33);
digitalWrite(13,LOW);
delay(3.33);
digitalWrite(8,HIGH);
delay(3.34);
digitalWrite(12,LOW);
delay(3.33);
digitalWrite(13,HIGH);
delay(3.33);
digitalWrite(8,LOW);
delay(3.34);
digitalWrite(12,HIGH);
}
}
