#define Moisture_pin A2
Int sensorValue;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
serial.print("Sensor: ");
serial.println(sensorValue);
delay(500);
}
