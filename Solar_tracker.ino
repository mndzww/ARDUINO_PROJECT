
#include <Servo.h>
#include <ESP8266wifi.h>
#include <ESP8266WebServer.h>

Servo servoX;
Servo servoY;

const int ldrLeftDown = A0;
const int ldrLeftRight = A1;
const int ldrUpLeft = A2;
const int ldrUpRight = A3;

const char *ssid = "NamaWiFi";
const char *password = "PasswordWiFi";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  servoX.attach(D5); // Hubungkan servo X ke pin D5 pada NodeMCU
  servoY.attach(D6); // Hubungkan servo Y ke pin D6 pada NodeMCU

  // Menghubungkan ke WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "Hello from ESP8266!");
  });

  server.begin();
}

void loop() {
  server.handleClient();

  int ldrValues[4];
  
  ldrValues[0] = analogRead(ldrLeftDown);
  ldrValues[1] = analogRead(ldrLeftRight);
  ldrValues[2] = analogRead(ldrUpLeft);
  ldrValues[3] = analogRead(ldrUpRight);

  int deltaX = ldrValues[1] - ldrValues[0];
  int deltaY = ldrValues[3] - ldrValues[2];

  int angleX = map(deltaX, -1023, 1023, 0, 180);
  int angleY = map(deltaY, -1023, 1023, 0, 180);

  servoX.write(angleX);
  servoY.write(angleY);

  delay(1000); // Delay untuk stabilisasi
}
