#include <WiFi.h>
#include <WebServer.h>


// WiFi network
const char* ssid     = "HOME - 2.4 GHz";
const char* password = "0000000000.";
String Test = "EIEI";

WebServer server ( 80 );



char htmlResponse[3000];

void handleRoot() {

  snprintf ( htmlResponse, 3000,
"<!DOCTYPE html>
<html>
<head>
<title>Test</title>
</head>
<body>
<center>
<h1>Test wed login wifi</h1>
<form action="/action_page.php">
  Test1: <input type="text" name="Test1" size="35"><br><br>
  Test2: <input type="text" name="Test2" maxlength="4" size="35"><br><br>
  <input type="submit" value="Submit Test"><br><br>
</form>
<input type="submit" value="1"> <input type="submit" value="2">
</center>
</body>
</html>"); 

   server.send ( 200, "text/html", htmlResponse );  

}


void handleSave() {
  if (server.arg("hh")!= ""){
    Serial.println("Hours: " + server.arg("hh"));
  }

  if (server.arg("mm")!= ""){
    Serial.println("Minutes: " + server.arg("mm"));
  }

  if (server.arg("ss")!= ""){
    Serial.println("Seconds: " + server.arg("ss"));
  }

}


void setup() {

  // Start serial
  Serial.begin(115200);
  delay(10);

  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on ( "/", handleRoot );
  server.on ("/save", handleSave);

  server.begin();
  Serial.println ( "HTTP server started" );


}

void loop() {
  server.handleClient();
}
