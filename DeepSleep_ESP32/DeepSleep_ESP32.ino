/*
 * Wakeup esp 2 method
 *  1.Ticker RTC check timer
 *  2.Ticker with logic 
*/  

#define uS_TO_S_FACTOR 1000000ULL 
#define TIME_TO_SLEEP  60     

RTC_DATA_ATTR int bootCount = 0;

void setup(){
  Serial.begin(9600);
  delay(1000);

  ++bootCount;
  Serial.println("Boot number: " + String(bootCount));
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);    //wakeup ticker every 60 sec
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33,1);                      //wakeup ticker pin 33 high with pulse
  Serial.println("Going to deep sleep now");
//  esp_deep_sleep_start();
}

void loop(){
  Serial.println(millis());
  if (millis() > 10 * 1000) { //deep leep every 10 sec
    esp_deep_sleep_start(); 
  }
}
