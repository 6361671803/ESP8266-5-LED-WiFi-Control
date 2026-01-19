#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// CHANGE THESE
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

// LED pins
int led1 = D1;
int led2 = D2;
int led3 = D3;
int led4 = D4;
int led5 = D5;

void setup() {
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html",
      "<h2>ESP8266 5 LED Control</h2>"
      "<a href='/1on'>LED1 ON</a><br>"
      "<a href='/1off'>LED1 OFF</a><br><br>"
      "<a href='/2on'>LED2 ON</a><br>"
      "<a href='/2off'>LED2 OFF</a><br><br>"
      "<a href='/3on'>LED3 ON</a><br>"
      "<a href='/3off'>LED3 OFF</a><br><br>"
      "<a href='/4on'>LED4 ON</a><br>"
      "<a href='/4off'>LED4 OFF</a><br><br>"
      "<a href='/5on'>LED5 ON</a><br>"
      "<a href='/5off'>LED5 OFF</a>"
    );
  });

  server.on("/1on", [](){ digitalWrite(led1, HIGH); server.send(200,"text/plain","LED1 ON"); });
  server.on("/1off", [](){ digitalWrite(led1, LOW); server.send(200,"text/plain","LED1 OFF"); });

  server.on("/2on", [](){ digitalWrite(led2, HIGH); server.send(200,"text/plain","LED2 ON"); });
  server.on("/2off", [](){ digitalWrite(led2, LOW); server.send(200,"text/plain","LED2 OFF"); });

  server.on("/3on", [](){ digitalWrite(led3, HIGH); server.send(200,"text/plain","LED3 ON"); });
  server.on("/3off", [](){ digitalWrite(led3, LOW); server.send(200,"text/plain","LED3 OFF"); });

  server.on("/4on", [](){ digitalWrite(led4, HIGH); server.send(200,"text/plain","LED4 ON"); });
  server.on("/4off", [](){ digitalWrite(led4, LOW); server.send(200,"text/plain","LED4 OFF"); });

  server.on("/5on", [](){ digitalWrite(led5, HIGH); server.send(200,"text/plain","LED5 ON"); });
  server.on("/5off", [](){ digitalWrite(led5, LOW); server.send(200,"text/plain","LED5 OFF"); });

  server.begin();
}

void loop() {
  server.handleClient();
}
