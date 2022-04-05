#define pwm_pin 10
void setup() {
  // Pins D3 and D11 - 62.5 kHz
  TCCR2B = 0b00000001; // x1
  TCCR2A = 0b00000011; // fast pwm
  pinMode(pwm_pin,OUTPUT);
 }
void loop() {
  analogWrite(pwm_pin,128);
}
