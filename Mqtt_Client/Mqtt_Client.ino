#include <WiFi.h>
#include <PubSubClient.h>

#define WIFI_STA_NAME "beam"
#define WIFI_STA_PASS "beam2539"

#define MQTT_SERVER   "178.128.80.51"
#define MQTT_PORT     1883
#define MQTT_USERNAME "mqtttest"
#define MQTT_PASSWORD "testmqtt"
#define MQTT_NAME     "ESP32"

#define PWM_PIN 23
#define Z_C_PIN 22

int DimmerValue = 100;

hw_timer_t *timer = NULL;

WiFiClient client;
PubSubClient mqtt(client);

void DimmerSetup() {
  pinMode(PWM_PIN, OUTPUT); 
  pinMode(Z_C_PIN, INPUT);
  
  attachInterrupt(Z_C_PIN, [](){
    if (DimmerValue > 5) {
      timerAlarmWrite(timer, DimmerValue * 100, true);
      timerAlarmEnable(timer);
      timerStart(timer);
    } else {
      digitalWrite(PWM_PIN, HIGH);
    }
  }, RISING);

  timer = timerBegin(3, 80, true);
  timerAttachInterrupt(timer, [](){
    digitalWrite(PWM_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(PWM_PIN, LOW);
    timerStop(timer);
  }, true);
}

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String topic_str = topic, payload_str = (char*)payload;
  Serial.println("[" + topic_str + "]: " + payload_str);

  DimmerValue = 100 - payload_str.toInt();
  Serial.println("Set light to " + String(payload_str.toInt()) + "%");
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_STA_NAME);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_STA_NAME, WIFI_STA_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  mqtt.setServer(MQTT_SERVER, MQTT_PORT);
  mqtt.setCallback(callback);
  
  DimmerSetup();
}

void loop() {
  if (mqtt.connected() == false) {
    Serial.print("MQTT connection... ");
    if (mqtt.connect(MQTT_NAME, MQTT_USERNAME, MQTT_PASSWORD)) {
      Serial.println("connected");
      //recvice from mqtt 
      mqtt.subscribe("Test_recvice");
    } else {
      Serial.println("failed");
      delay(5000);
    }
  } 
  else {
    mqtt.loop();
  }


//send to mqtt 
  delay(3000);
  mqtt.publish("Test_send", "test sent");
}
