#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "xxxxxxxxxx";
const char* password = "xxxxxxxxxxxx";

// sensor parameter
const int sensorPin = A0;
int state = 0;
int speakerPin = D5;

void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(sensorPin,INPUT);
  pinMode(speakerPin, OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }

}
 
void loop() {
  state = analogRead(sensorPin);
  if(state < 500) {
      if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
       
      HTTPClient http;  //Declare an object of class HTTPClient
      String value = (String) state;
      http.begin("http://jagorobot.pythonanywhere.com/kirimwa?nilai=" + value);  // send POST WA notification
      int httpCode = http.GET();   
       
      if (httpCode > 0) {
        String payload = http.getString();  
        Serial.println(payload);     
      }
        http.end();   //Close connection
      }
      // turn on alarm
      digitalWrite(speakerPin, HIGH);
      delay(3000);
      digitalWrite(speakerPin, LOW);
      delay(1000);
  }
  delay(500);
}
