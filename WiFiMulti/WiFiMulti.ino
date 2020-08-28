/*
 *  This sketch trys to Connect to the best AP based on a given list
 *
 */

#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;
bool connectWIFI;
void setup()
{
    Serial.begin(115200);
    delay(10);

    wifiMulti.addAP("HOME - 2.4 GHz", "0000000000.");
    wifiMulti.addAP("Pencil", "0000000000.");
    wifiMulti.addAP("SSID", "PASS");

    Serial.println("Connecting Wifi...");
    if(wifiMulti.run() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
}

void loop()
{
    if(wifiMulti.run() != WL_CONNECTED) {
        Serial.println("WiFi not connected!");
        delay(1000);
        connectWIFI = true;
    }
    else{
      if(connectWIFI){
        Serial.print("WiFi connected IP address: ");
        Serial.println(WiFi.localIP());
        connectWIFI = false;
      }
    }
}
