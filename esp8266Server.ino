/*Aspro Company 
 * Eng:Amir Salama
 * https://www.youtube.com/@amirsalama9928/videos
 * https://www.facebook.com/groups/2187431451581099
 * https://www.facebook.com/profile.php?id=100091664624422
 */
#include <ESP8266WiFi.h>

WiFiServer server(6000);
IPAddress IP(192,168,4,15);
IPAddress mask = (255, 255, 255, 0);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("ASPro", "12345678");
  WiFi.softAPConfig(IP, IP, mask);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {return;}
  //Serial.println(client.remoteIP());
  String request = client.readStringUntil('#');
  //Serial.println("********************************");
  if(request !=""){
  Serial.println(request);
  }
  client.flush();
  client.println("ggg\r");
  //client.stop();
}
