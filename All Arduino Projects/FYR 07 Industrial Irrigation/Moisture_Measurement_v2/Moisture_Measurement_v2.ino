#define Moisture_pin A1
int sensorValue;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Moisture_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue=analogRead(Moisture_pin);
Serial.println("\n");
Serial.print("Moisture value: ");
Serial.print(sensorValue);
delay(500);
Serial.print("\n");
}
