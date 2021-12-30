 // set pin numbers:
const int MainsSupplyPin = A0;     // the number of the pushbutton pin
const int RelayPin3 =  3;      // the number of the Relay pin
const int RelayPin4 =  4;
const int GenSwitchPin5 =  A1;
// variables will change:
int MainsSupplyState = 0;         // variable for reading the MainsSupplybutton status
int GenSwitchState = 0;         // variable for reading the GenSwitchbutton status

void setup() {
  // initialize the Relay pin3 as an output:
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(MainsSupplyPin, INPUT);
  pinMode(GenSwitchPin5, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  MainsSupplyState = digitalRead(MainsSupplyPin);
  GenSwitchState=digitalRead(GenSwitchPin5);
  // check if the MainsSupplybutton is pressed.
  // if it is, the MainsSupplyState is HIGH:
  if (MainsSupplyState == HIGH && GenSwitchState==HIGH) {
    // turn Relay on:
    digitalWrite(RelayPin4, LOW);
    digitalWrite(RelayPin3, HIGH);
    delay(1000);
  } else if (MainsSupplyState == HIGH && GenSwitchState==LOW) {
    // turn Relay off:
    digitalWrite(RelayPin3, HIGH);
    digitalWrite(RelayPin4, LOW);
    delay(1000);
  } else if (MainsSupplyState == LOW && GenSwitchState==HIGH){
    //
    digitalWrite(RelayPin3, LOW);
    digitalWrite(RelayPin4, HIGH);
    delay(1000);
    }else{
      //
    digitalWrite(RelayPin3, LOW);
    digitalWrite(RelayPin4, LOW);
    delay(1000);
      }
}
