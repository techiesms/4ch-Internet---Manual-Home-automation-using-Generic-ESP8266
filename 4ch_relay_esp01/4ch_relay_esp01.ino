/*
 * This is the code for the project
 * "Internet & Manual Controlled 4ch Automation' 
 * which is Uploaded on techiesms YouTube Channel
 * 
 * You can watch the full tutorial from here
 * https://youtu.be/tvZ0XZWYe8U
 * 
 * 
 *        techiesms
 * explore | learn | share
 * 
 */

/****************************************
   Include Libraries
 ****************************************/
#include "UbidotsESPMQTT.h" // Download the libray from here https://github.com/ubidots/ubidots-mqtt-esp

/****************************************
   Define Constants
 ****************************************/
#define WIFINAME "SmS_jiofi" //Your SSID
#define WIFIPASS "sms123458956" // Your Wifi Pass
#define TOKEN "BBFF-4eoB0mUpfvAgV8RD9DRLTg1iE0Z5Kt" // Your Ubidots TOKEN


#define r1 0
#define r2 1
#define r3 2
#define r4 3


Ubidots client(TOKEN);

/****************************************
   Auxiliar Functions
 ****************************************/

void callback(char* topic, byte* payload, unsigned int length) {

  if ((String)topic == "/v1.6/devices/esp-01/r1/lv")
  {
    int mytopic = atoi(topic);
    payload[length] = '\0';
    int mymsg = atoi ((const char*)payload);

    int val1 = mymsg;
    digitalWrite(r1, val1);
  }

  else if ((String)topic == "/v1.6/devices/esp-01/r2/lv")
  {

    int mytopic = atoi(topic);
    payload[length] = '\0';
    int mymsg = atoi ((const char*)payload);

    int val1 = mymsg;
    digitalWrite(r2, val1);
  }
  else if ((String)topic == "/v1.6/devices/esp-01/r3/lv")
  {

    int mytopic = atoi(topic);
    payload[length] = '\0';
    int mymsg = atoi ((const char*)payload);

    int val1 = mymsg;
    digitalWrite(r3, val1);
  }
  else if ((String)topic == "/v1.6/devices/esp-01/r4/lv")
  {

    int mytopic = atoi(topic);
    payload[length] = '\0';
    int mymsg = atoi ((const char*)payload);

    int val1 = mymsg;
    digitalWrite(r4, val1);
  }
  else
  {}
}
//Serial.println();

/****************************************
   Main Functions
 ****************************************/

void setup() {
  // put your setup code here, to run once:
  client.ubidotsSetBroker("business.api.ubidots.com"); // Sets the broker properly for the business account
  client.setDebug(true); // Pass a true or false bool value to activate debug messages
  client.wifiConnection(WIFINAME, WIFIPASS);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  client.begin(callback);
  client.ubidotsSubscribe("esp-01", "r1"); //Insert the dataSource and Variable's Labels
  client.ubidotsSubscribe("esp-01", "r2"); //Insert the dataSource and Variable's Labels
  client.ubidotsSubscribe("esp-01", "r3"); //Insert the dataSource and Variable's Labels
  client.ubidotsSubscribe("esp-01", "r4"); //Insert the dataSource and Variable's Labels
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    client.reconnect();
    client.ubidotsSubscribe("esp-01", "r1"); //Insert the dataSource and Variable's Labels
    client.ubidotsSubscribe("esp-01", "r2"); //Insert the dataSource and Variable's Labels
    client.ubidotsSubscribe("esp-01", "r3"); //Insert the dataSource and Variable's Labels
    client.ubidotsSubscribe("esp-01", "r4"); //Insert the dataSource and Variable's Labels
  }
  client.loop();
}
