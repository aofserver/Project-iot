#include "WiFi.h"
#include "FS.h"
#include "SPIFFS.h"

String text;
String results[20];
bool scanwifi = true;
bool ssidd = false; 
bool passs = false;
bool connectedd = false;
char ssid[50];
char pass[50]; 
int cnt_input = 0;

#define FORMAT_SPIFFS_IF_FAILED true

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
}

void loop() {
  scanWIFI();

  if(Serial.available()){
    char c = Serial.read();
    if(c != '\n'){
      text += c;
    }
    else{
      Serial.println(text);
      cnt_input++;
      
      if(cnt_input == 1){
        int num = text.toInt(); 
        String text = results[num];
        text.toCharArray(ssid,50);
        ssidd = true;
        Serial.print("Connect to ");
        Serial.println(ssid);
        Serial.print("Enter your passsword: ");
      }
      if(cnt_input == 2){
        text.toCharArray(pass,50);
        passs = true;
      }

      if(ssidd & passs){
        connactWIFI();
        String user_pass = String(ssid) + "," + String(pass);
        Serial.print("Save User Pass : ");
        Serial.println(user_pass);

      }

      if(text == "!scanwifi"){
        scanwifi = true;
        cnt_input = 0;
      }
      
      text.clear();
    }
  }
  
  reconnectWIFI();
  
}


void scanWIFI(){
  if(scanwifi == true){
    Serial.println("scan start");
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
      Serial.println("no networks found");
    } else {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i) {
        results[i + 1] = WiFi.SSID(i);
        
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(results[i + 1]);
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.print(")");
        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
        delay(10);
      }
      Serial.println("Select WiFi Number : ");
      scanwifi = false;
      connectedd = false;
      ssidd = false;
      passs = false;
    }
    Serial.println("");
    delay(5000);
  }  
}

void connactWIFI(){
  if(connectedd != true){      
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);

    Serial.print("Connecting to ");
   
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }

     Serial.println("");
     Serial.println("WiFi connected");
     Serial.print("IP address: ");
     Serial.println(WiFi.localIP());
     connectedd = true;
   }
}

void reconnectWIFI(){
    if((WiFi.status() != WL_CONNECTED) && ssid != NULL && pass != NULL & connectedd == true) {
      connectedd = false;
      connactWIFI();
    }
}








////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////







void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
    Serial.printf("Listing directory: %s\r\n", dirname);

    File root = fs.open(dirname);
    if(!root){
        Serial.println("- failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println(" - not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file){
        if(file.isDirectory()){
            Serial.print("  DIR : ");
            Serial.println(file.name());
            if(levels){
                listDir(fs, file.name(), levels -1);
            }
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("\tSIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}

void readFile(fs::FS &fs, const char * path){
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path);
    if(!file || file.isDirectory()){
        Serial.println("- failed to open file for reading");
        return;
    }

    Serial.println("- read from file:");
    while(file.available()){
        Serial.write(file.read());
    }
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\r\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("- failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("- file written");
    } else {
        Serial.println("- frite failed");
    }
}

void appendFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Appending to file: %s\r\n", path);

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("- failed to open file for appending");
        return;
    }
    if(file.print(message)){
        Serial.println("- message appended");
    } else {
        Serial.println("- append failed");
    }
}

void renameFile(fs::FS &fs, const char * path1, const char * path2){
    Serial.printf("Renaming file %s to %s\r\n", path1, path2);
    if (fs.rename(path1, path2)) {
        Serial.println("- file renamed");
    } else {
        Serial.println("- rename failed");
    }
}

void deleteFile(fs::FS &fs, const char * path){
    Serial.printf("Deleting file: %s\r\n", path);
    if(fs.remove(path)){
        Serial.println("- file deleted");
    } else {
        Serial.println("- delete failed");
    }
}

void testFileIO(fs::FS &fs, const char * path){
    Serial.printf("Testing file I/O with %s\r\n", path);

    static uint8_t buf[512];
    size_t len = 0;
    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("- failed to open file for writing");
        return;
    }

    size_t i;
    Serial.print("- writing" );
    uint32_t start = millis();
    for(i=0; i<2048; i++){
        if ((i & 0x001F) == 0x001F){
          Serial.print(".");
        }
        file.write(buf, 512);
    }
    Serial.println("");
    uint32_t end = millis() - start;
    Serial.printf(" - %u bytes written in %u ms\r\n", 2048 * 512, end);
    file.close();

    file = fs.open(path);
    start = millis();
    end = start;
    i = 0;
    if(file && !file.isDirectory()){
        len = file.size();
        size_t flen = len;
        start = millis();
        Serial.print("- reading" );
        while(len){
            size_t toRead = len;
            if(toRead > 512){
                toRead = 512;
            }
            file.read(buf, toRead);
            if ((i++ & 0x001F) == 0x001F){
              Serial.print(".");
            }
            len -= toRead;
        }
        Serial.println("");
        end = millis() - start;
        Serial.printf("- %u bytes read in %u ms\r\n", flen, end);
        file.close();
    } else {
        Serial.println("- failed to open file for reading");
    }
}
