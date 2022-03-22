// Not complete still under review
#include <AVR_RTC.h>

void setup() {
  // put your setup code here, to run once:
 setup_RTC_interrupt();
 Serial.begin(9600);
 tm CurrTimeDate; 
 set_system_time( mktime( (tm*)&CurrTimeDate));
}

void loop() {
  // put your main code here, to run repeatedly:
time_t currentTick;       // set up a location for the current time stamp since the 

time((time_t *)&currentTick);

  Serial.println(ctime( (time_t *)&currentTick));

  delay(2000);
}
