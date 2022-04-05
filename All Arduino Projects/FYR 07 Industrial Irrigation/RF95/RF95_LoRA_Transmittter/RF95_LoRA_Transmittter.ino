// Arduino Transmitter Node
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messaging client (transmitter)
// with the RH_RF95 class. RH_RF95 class does not provide for addressing or
// reliability, so you should only use RH_RF95 if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example LoRa9x_RX

#include <SPI.h>
#include <RH_RF95.h>
//#include <SimpleTimer.h>

#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 2

// Change to 434.0 or other frequency, must  match RX's freq!
#define RF95_FREQ 868.3
//SimpleTimer timer;

//int timerId = 0;

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT); // Constructor
void callMeLater() {
    // do something
    Serial.println("timed out...................what to do next");
      // manual reset
  //digitalWrite(RFM95_RST, LOW);
  //delay(10);
  //digitalWrite(RFM95_RST, HIGH);
  //delay(10);
}



void setup() 
{
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

  while (!Serial);
  Serial.begin(9600);
  delay(100);

  Serial.println("Arduino LoRa TX Test!");

  // manual reset
  digitalWrite(RFM95_RST, LOW);
  delay(1000);
  digitalWrite(RFM95_RST, HIGH);
  delay(1000);

  while (!rf95.init()) {
    delay(100);
    Serial.println("LoRa radio init failed");
    while (1);
  }
  Serial.println("LoRa radio init OK!");

  // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("setFrequency failed");
    while (1);
  }
  Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);
  
  // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on

  // The default transmitter power is 13dBm, using PA_BOOST.
  // If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then 
  // you can set transmitter powers from 5 to 23 dBm:
  //rf95.setTxPower(23, false);
  
}

int16_t packetnum = 0;  // packet counter, we increment per xmission

void loop()
{
  Serial.println("Sending to rf95_server");
  // Send a message to rf95_server
  
  char radiopacket[20] = "Hello World #      ";
  itoa(packetnum++, radiopacket+13, 10);
  Serial.print("Sending "); Serial.println(radiopacket);
  radiopacket[19] = 0;
  
  Serial.println("Sending..."); delay(10);
  rf95.send((uint8_t *)radiopacket, 20);

  Serial.println("Waiting for packet to complete..."); delay(100);
//  timerId = timer.setTimeout(6000, callMeLater);
//  timer.run();
  rf95.waitPacketSent();
//  timer.disable(timerId);
  // Now wait for a reply
  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  delay(100);
//  timerId = timer.setTimeout(6000, callMeLater);
//  timer.run();
  Serial.println("Waiting for reply just after timer all before rf95.available..."); 
  //delay(4000);
  //if (rf95.waitAvailableTimeout(5000))
  while(!rf95.available()){
    if (rf95.available())
      { 
        break;
      }
  }
  //timer.disable(timerId);
  
  if (rf95.available())
  { 
    //Serial.print("waitng for reply but got message: ");
    // Should be a reply me ssage for us now   
    if (rf95.recv(buf, &len))
   {
      //timer.disable(timerId);
      Serial.print("Got reply: ");
      Serial.println((char*)buf);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);    
    }
    else
    {
      delay(100);
      //timer.disable(timerId);
      Serial.println("Receive failed");
    }
  }
  else
  {
    Serial.println("No reply, is there a listener around?");
  }
  //timer.disable(timerId);
  delay(1000);
}
