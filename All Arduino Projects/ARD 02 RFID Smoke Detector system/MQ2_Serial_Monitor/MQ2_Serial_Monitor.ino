/* This code is made by GreHiDeL M
 * The following code will use the MQ-2 gas sensor and
 * uses prints the sensor value in the serial monitor
 */
int gas_sensorPin=A0;
// this is the pin which we have declared as the analogPin that is A0
int sensorThreshold=120;
// this is the minimum value which when exceeded smoke is detected.
void setup() {
  // put your setup code here, to run once:
  pinMode(gas_sensorPin,INPUT);
  // note that gas_sensorPin as declared as an input pin
  Serial.begin(9600);
  // Begin the serial monitor with 9600 baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int state=0;
  // This is a variable which to read the gas sensor analog pin
  state=analogRead(A0);
  // we assign state as the value of the analogRead the analog pin
  Serial.println(state);
  // prints the state in a different line
  

}// END OF THE CODE.
