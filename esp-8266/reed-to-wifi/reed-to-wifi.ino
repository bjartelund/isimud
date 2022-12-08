#include <ESP8266WiFi.h>
#include <secrets.h>
const char* ssid = "bjartea52";
const char* password = "projectisimud";
const char* host = "maker.ifttt.com";
const char* iftttApiKey = SECRET_APIKEY ;//IFTTT API SECRET  KEY defined in secrets.h
const char* door_state = "closed";

const int pin = 2;//GPIO2
volatile int state = false;
volatile int flag = false;
const long interval = 3000;
unsigned long previousMillis = 0; 

void doorStatusChange() {

    unsigned long currentMillis = millis();
 
    if(currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;   
    
        state = !state;
        if(state) {
            door_state = "opened";
        }
        else{
            door_state = "closed";
        }
        flag = true;
        Serial.println(state);
        Serial.println(door_state);
    }    
}

void setup() {
    //pinMode(pin, OUTPUT);
    //attachInterrupt(digitalPinToInterrupt(pin), doorStatusChange, CHANGE);
    Serial.begin(115200);
    flag=true;

}

void loop() {

      if(flag){
            Serial.println();
             Serial.print("Connecting to ");
            Serial.println(ssid);    
            WiFi.begin(ssid, password);    
            while (WiFi.status() != WL_CONNECTED) {
               delay(500);
            }      
                Serial.println();
          Serial.println("WiFi connected");  
          Serial.print("IP address: ");
          Serial.println(WiFi.localIP());  
          WiFiClient client;          
          if (!client.connect(host, 80)) {
            Serial.println("connection failed");
            return;
          }
    
          String url = "/trigger/mailbox_opened/with/key/";
          url += iftttApiKey;
          Serial.print("URL: ");
          Serial.println(url);
          client.print(String("POST ") + url + " HTTP/1.1\r\n" +
                       "Host: " + host + "\r\n" + 
                       "Content-Type: application/x-www-form-urlencoded\r\n" + 
                       "Content-Length: 13\r\n\r\n" +
                       "value1=" + door_state + "\r\n");
          while (client.connected()) {
              String line = client.readStringUntil('\n');
              if (line == "\r") {
                Serial.println("headers received");
                break;
              }
            }
            String line = client.readString();
            Serial.println("reply below (if blank this usually means successful:");
            Serial.println("==========");
            Serial.println(line);
            Serial.println("==========");
            Serial.println("closing connection");
          }
          flag = false;
        
      delay(500);
}
