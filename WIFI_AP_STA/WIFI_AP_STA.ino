#include <WiFi.h>

#define SSID_AP "ConfigWifi"
#define PASS_AP "0000000000."
#define SSID_STA "Pencil"
#define PASS_STA "0000000000."
 
void setup() {
  Serial.begin(115200);
//  WiFi.disconnect();
  WiFi.mode(WIFI_AP_STA);
  delay(100);
  WiFi.softAP(SSID_AP,PASS_AP);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
  Serial.print("Connecting to ");
  WiFi.begin(SSID_STA,PASS_STA);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
