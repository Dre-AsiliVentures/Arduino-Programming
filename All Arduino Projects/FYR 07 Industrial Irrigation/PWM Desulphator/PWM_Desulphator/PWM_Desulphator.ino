// This  a code for a PWM Desulphator for battery maintenance
#define pwm_pin 7
void setup() {
 // Pins D3 and D11 - 62.5 kHz
  TCCR4B = 0b00000001; // x1
  TCCR4A = 0b00000011; // fast pwm
  pinMode(pwm_pin,OUTPUT);
}
void loop() {
  analogWrite(pwm_pin, 50);
}
