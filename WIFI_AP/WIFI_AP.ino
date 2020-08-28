#include<WiFi.h>
#include "TonyS_X1.h"

const char* ssid = "HOME - 2.4 GHz";
const char* password = "0000000000.";

void setup() {
  Serial.begin(115200);
  Tony.begin();
  
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() { }
