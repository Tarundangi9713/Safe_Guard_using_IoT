#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "shubhamraikwar6"
#define DEVICE_ID "NM1"
#define DEVICE_CREDENTIAL "oxjXRt2gQ6Xx"

#define SSID "abcd"
#define SSID_PASSWORD "Sr010799"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

int pushPin = D5; //  Pin 6 on Node MCU   //the digital pin connected to the PIR sensor's output
int ledPin = D2;  // Pin 2 on NodeMCU
int val = 0;     // variable for reading the pin status


void setup() {

   pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(pushPin, INPUT_PULLUP);// declare pushbutton as input
  Serial.begin(9600);
  
    //connecting to WIFI
   thing.add_wifi(SSID,SSID_PASSWORD);
  Serial.println("entering the gates");
} 

/*
void loop() {
  thing.handle();
} */

//

void loop(){

 val = digitalRead(pushPin);
  Serial.println(val);// read input value
  if (val == LOW) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin, HIGH);  // turn LED OFF
    delay(1000);
        digitalWrite(ledPin, LOW);
      
      thing.handle();
           thing.call_endpoint("Email");
           delay(4000);
   // digitalWrite(inPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);  // turn LED ON
  }
    
}

 
