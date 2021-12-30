  //East lane pins
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27
int east_red = 10;
int east_yellow = 9;
int east_green = 8;

  //south lane pins
int south_red = 2;
int south_yellow = 30;
int south_green = 28;

  //west lane pins
int west_red = 31;
int west_yellow = 33;
int west_green = 35;

  //north lane pins
int north_red = 5;
int north_yellow = 4;
int north_green = 3;

  //pedestrian pins
int red = 24;
int green = 26;

void setup() {
  // put your setup code here, to run once:
    // declering pins as outputs
lcd.init();  
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("WYCLIFFE& RYAN");
delay(1000);
pinMode (east_red, OUTPUT);
pinMode (east_yellow, OUTPUT);
pinMode (east_green, OUTPUT);

pinMode (south_red, OUTPUT);
pinMode (south_yellow, OUTPUT);
pinMode (south_green, OUTPUT);

pinMode (west_red, OUTPUT);
pinMode (west_yellow, OUTPUT);
pinMode (west_green, OUTPUT);

pinMode (north_red, OUTPUT);
pinMode (north_yellow, OUTPUT);
pinMode (north_green, OUTPUT);

pinMode (red, OUTPUT);
pinMode (green, OUTPUT);


}

void north_south_on(){
digitalWrite(north_green, HIGH);
digitalWrite(east_red, HIGH);
digitalWrite(south_green, HIGH);
digitalWrite(west_red, HIGH);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("ARD13 TRAFFIC");
lcd.setCursor(3,1);
lcd.print("NORTH SOUTH");
}
void north_south_off(){
  digitalWrite(north_green, LOW);
  digitalWrite(east_red, LOW);
  digitalWrite(south_green, LOW);
  digitalWrite(west_red, LOW);  
}
void east_west_on(){
  digitalWrite(east_green, HIGH);
  digitalWrite(north_red, HIGH);
  digitalWrite(west_green, HIGH);
  digitalWrite(south_red, HIGH); 
lcd.clear();
lcd.setCursor(0,0);
lcd.print("ARD13 TRAFFIC");
lcd.setCursor(4,1);
lcd.print("EAST WEST");
}
void east_west_off(){
  digitalWrite(east_green, LOW);
  digitalWrite(north_red, LOW);
  digitalWrite(west_green, LOW);
  digitalWrite(south_red, LOW);    
}
void wait_on(){
  digitalWrite(east_yellow, HIGH);
  digitalWrite(north_yellow, HIGH);
  digitalWrite(west_yellow, HIGH);
  digitalWrite(south_yellow, HIGH);  
}
void wait_off(){
  digitalWrite(east_yellow, LOW);
  digitalWrite(north_yellow, LOW);
  digitalWrite(west_yellow, LOW);
  digitalWrite(south_yellow, LOW);  
}
void red_on(){
  digitalWrite(east_red, HIGH);
  digitalWrite(north_red, HIGH);
  digitalWrite(west_red, HIGH);
  digitalWrite(south_red, HIGH);  
}
void red_off(){
  digitalWrite(east_red, LOW);
  digitalWrite(north_red, LOW);
  digitalWrite(west_red, LOW);
  digitalWrite(south_red, LOW);  
}
void green_off(){
  digitalWrite(east_green, LOW);
  digitalWrite(north_green, LOW);
  digitalWrite(west_green, LOW);
  digitalWrite(south_green, LOW);  
}
void pedestrians_on(){
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("ARD13 TRAFFIC");
lcd.setCursor(1,1);
lcd.print("PEDESTRIAN PASS");
}
void pedestrians_off(){
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

//north-south lane  
north_south_on();
east_west_off();
pedestrians_off();
wait_off();
delay(5000);

north_south_on();
east_west_off();
pedestrians_off();
wait_on();
delay(5000);

//east-west lane
east_west_on();
north_south_off();
pedestrians_off();
wait_off();
delay(5000);

east_west_on();
north_south_off();
pedestrians_off();
wait_off();
delay(5000);

//pedestrians 
pedestrians_on ();
east_west_off();
north_south_off();
red_on();
wait_off();
delay(5000);

pedestrians_on ();
east_west_off();
north_south_off();
red_on();
digitalWrite(north_yellow, HIGH);
digitalWrite(south_yellow, HIGH);
delay(5000);
}
