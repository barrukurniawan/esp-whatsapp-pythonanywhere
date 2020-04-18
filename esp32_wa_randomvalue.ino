#include "WiFi.h"
#include "HTTPClient.h"
#include "base64.h"

// Setup WiFi network
const char* ssid = "xxxxxxxxxx";
const char* password = "xxxxxxxxxx";

// Twilio Parameter
String account_sid = "Axxxxxxxxxxxxxxxxxxxxxxxxxx";
String auth_token = "8xxxxxxxxxxxxxxxxxxxxxxxxx";
String from = "whatsapp:+14155238886";
String to = "whatsapp:+xxxxxxxxxxx";
String body = "Terdeteksi ada penyusup masuk";

void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to WiFi");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    int nilai = random(29,37);
    String data = (String) nilai;
    String link = "https://jagorobot.pythonanywhere.com/kirimwa?nilai=" + data;
    
    http.begin(link,"16 BA B9 9E 77 4C FF 0B 25 07 DE F9 AC 1A 23 E3 1A B2 AE EB");
    int httpCode = http.GET();
    
    if (httpCode > 0) { //Check for the returning code
        
        String payload = http.getString();
        Serial.println(link);
        Serial.println(httpCode);
        Serial.println(payload);
    }
    else {
        Serial.println("Error on HTTP request");
    }
    
    http.end();
    
  }  
  delay(5000);
 
}
