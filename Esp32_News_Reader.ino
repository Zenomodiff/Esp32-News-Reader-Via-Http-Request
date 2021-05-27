/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 12:06 AM - date 28 may 2021
 Github Link :-- https://github.com/Zenomodiff/Esp32-News-Reader-Via-Http-Request
 */

#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "PASTE WIFI NAME";
const char* password =  "PASTE WIFI PASSWORD";

void apiCall(){
  
if ((WiFi.status() == WL_CONNECTED)) {
HTTPClient http;

http.begin("PASTE THE HTTP LINK");

int httpCode = http.GET();
if (httpCode == 200) {
 
String payload = http.getString();
const size_t capacity = JSON_ARRAY_SIZE(20) + 20*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + 20*JSON_OBJECT_SIZE(8) + 19020;
        
DynamicJsonDocument doc(capacity);
DeserializationError error = deserializeJson(doc, payload);
        
if (error) {
   
Serial.print(F("De-serialisation Error"));
return;
}
JsonArray articles = doc["articles"];
JsonObject articles_0 = articles[0];
JsonObject articles_1 = articles[1];
JsonObject articles_2 = articles[2];
JsonObject articles_3 = articles[3];
JsonObject articles_4 = articles[4];
JsonObject articles_5 = articles[5];
JsonObject articles_6 = articles[6];
JsonObject articles_7 = articles[7];
JsonObject articles_8 = articles[8];
JsonObject articles_9 = articles[9];
JsonObject articles_10 = articles[10];

const char* articles_0_title = articles_0["title"];
const char* articles_1_title = articles_1["title"];
const char* articles_2_title = articles_2["title"];
const char* articles_3_title = articles_3["title"];
const char* articles_4_title = articles_4["title"];
const char* articles_5_title = articles_5["title"];
const char* articles_6_title = articles_6["title"];
const char* articles_7_title = articles_7["title"];
const char* articles_8_title = articles_8["title"];
const char* articles_9_title = articles_9["title"];
const char* articles_10_title = articles_10["title"];

Serial.println("TYPE THE NEWS CATEGORY NAME FROM HTTP LINK");
Serial.println("********************************************************************************************************");
Serial.println(articles_0_title);
Serial.println(articles_1_title);
Serial.println(articles_2_title);
Serial.println(articles_3_title);
Serial.println(articles_4_title);
Serial.println(articles_5_title);
Serial.println(articles_6_title);
Serial.println(articles_7_title);
Serial.println(articles_8_title);
Serial.println(articles_9_title);
Serial.println(articles_10_title);
Serial.println("********************************************************************************************************");
}

 else 
 {
Serial.println("Error HTTP-Request");
 }
http.end();
 }
 }

void setup() {
 
Serial.begin(115200);
WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting To Network ...");
  }
  Serial.println("Connected !");

}
 
void loop()
{
 
apiCall();
delay(10000);

}
