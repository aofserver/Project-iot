#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


// Config Firebase
#define FIREBASE_HOST "fir-46019.firebaseio.com"
#define FIREBASE_AUTH "8uHaCd6kbJy05BXUSGMgviAOXz5gMUKNsAkPJ7IM"

// Config connect WiFi
#define WIFI_SSID "HOME - 2.4 GHz"
#define WIFI_PASSWORD "00000000000."



String name;


void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  // Read temp & Humidity for DHT22
  float h = 1;
  float t = 1;

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(500);
    return;
  }

  // append a new value to /temperature
  name = Firebase.pushFloat("temperature", t);
  if (Firebase.failed()) {
      Serial.print("pushing /temperature failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /temperature/");
  Serial.println(name);

  // append a new value to /temperature
  name = Firebase.pushFloat("humidity", h);
  if (Firebase.failed()) {
      Serial.print("pushing /humidity failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /humidity/");
  Serial.println(name);
  
  delay(5000);
}
