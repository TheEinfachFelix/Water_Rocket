#include "wifi.hpp"
#include "WIFIconfig.hpp"


// Port des Web Servers auf 80 setzen
WiFiServer server(80);

// Variable für den HTTP Request
String header;
int TempWert = 0;


void wifiSetup(){

  // Mit dem WiFi-Netzwerk verbinden
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Lokale IP-Adresse im Seriellen Monitor ausgeben und Server starten
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.print("                ");
  Serial.println(WiFi.localIP());
  server.begin();

  if(MDNS.begin("ESP8266")){
    Serial.println("DNS gestartet!");
  }
}

void wifiLoop(){
     // Prüfen, ob sich ein Client verbunden hat
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Warten auf Daten vom Client
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Erste Zeile des Requests lesen
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=OFF") != -1)  {
    Serial.println("   0   ");
    value = HIGH;
  }
  if (request.indexOf("/LED=ON") != -1)  {
    Serial.println("   1   ");
    value = LOW;
  }
 
  // Anfrage zurücksenden
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Refresh: 0.5\r\n");

  client.println("\r\n");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println(millis());
 
  client.print("Die LED ist: ");
 
  if(value == HIGH) {
    client.print("Aus");
  } else {
    client.print("An");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>An </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Aus </button></a><br />");  
  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client trennen");
  Serial.println("");
}