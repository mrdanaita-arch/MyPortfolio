#include <WiFiS3.h>

const char* ssid = "arnon.2.4G";        // ชื่อ WiFi
const char* password = "12112525"; // รหัสผ่าน WiFi

WiFiServer server(80);

int trigPin = 2; // ขา Trig ของ HC-SR04
int echoPin = 3; // ขา Echo ของ HC-SR04
long duration;
int distance;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        currentLine += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            String state = getQueryParam(currentLine, "state");
            if (state == "on") {
              // เปิดอุปกรณ์
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println();
              client.println("<html><body><h1>Device is ON</h1></body></html>");
            } else if (state == "off") {
              // ปิดอุปกรณ์
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println();
              client.println("<html><body><h1>Device is OFF</h1></body></html>");
            } else {
              client.println("HTTP/1.1 400 Bad Request");
              client.println("Content-type:text/html");
              client.println();
              client.println("<html><body><h1>Invalid state</h1></body></html>");
            }
            break;
          } else {
            currentLine = "";
          }
        }
      }
    }
    delay(1);
    client.stop();
  }
}

String getQueryParam(String request, String param) {
  int startIndex = request.indexOf(param + "=");
  if (startIndex == -1) {
    return "";
  }
  startIndex += param.length() + 1;
  int endIndex = request.indexOf("&", startIndex);
  if (endIndex == -1) {
    endIndex = request.indexOf(" ", startIndex);
  }
  return request.substring(startIndex, endIndex);
}
