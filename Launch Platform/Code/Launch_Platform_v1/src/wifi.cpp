#include "wifi.hpp"
#include "WIFIconfig.hpp"


// Port des Web Servers auf 80 setzen
WiFiServer server(80);

// Variable für den HTTP Request
String header;

bool connection_debug = 0;


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
  

  if (!MDNS.begin(dns_adresse)) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  server.begin();
  MDNS.addService("http", "tcp", 80);
}

void wifiLoop(){

  MDNS.update();
     // Prüfen, ob sich ein Client verbunden hat
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // Warten auf Daten vom Client
  if(connection_debug) Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // Erste Zeile des Requests lesen
  String request = client.readStringUntil('\r');
  if(connection_debug) Serial.println(request);
  client.flush();






  // Match the request
  if(request.indexOf("readDHT11") != -1)
  {
    client.print(getADC(0));
    client.println("</p><p>millis: ");
    client.println(millis());
    client.println("</p>");
  } else{

  int Arm = LOW;
  if (request.indexOf("/AutoLaunch=ON") != -1)  {
    Serial.println("AutoLaunch=ON");
    
    setServo(servo_go);

  }
  if (request.indexOf("/ForceLaunch=ON") != -1)  {
    Serial.println("ForceLaunch=ON");
    
    setServo(servo_go);

  }
  if (request.indexOf("/ARM=OFF") != -1)  {
    Serial.println("ARM=OFF");
    Arm = LOW;
    setServo(servo_hold);
  }
  if (request.indexOf("/ARM=ON") != -1)  {
    Serial.println("ARM=ON");
    Arm = HIGH;
    
  }
 
  // Anfrage zurücksenden
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  //client.println("Refresh: 10\r\n");

  client.println("\r\n");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  // css

  if(Arm == HIGH) {
    client.println("<style>body{font-family: monaco, Consolas;background-color: Tomato;color: Black;font-size: 300%} button{width: 49%; height: 500%; border: none; font-size: 250%}</style>");

  } else {
    client.println("<style>body{font-family: monaco, Consolas;background-color: Cyan;color: Black;font-size: 300%} button{width: 49%; height: 500%; border: none; font-size: 250%}</style>");

  }


  // Buttons
  client.println("<h1>Raketen Startrampe</h1>");
  client.println("<a href=\"/ARM=ON\"\"><button style=\"background-color:orange\">ARM</button></a>");
  client.println("<a href=\"/ARM=OFF\"\"><button style=\"background-color:green\">DISARM</button></a>");
  client.println("<br>");
  client.println("<a href=\"/AutoLaunch=ON\"\"><button style=\"background-color:red\">Auto Launch</button></a>");
  client.println("<a href=\"/ForceLaunch=ON\"\"><button style=\"background-color:DimGray\">Force Launch</button></a>");  
  client.println("<br>");
  
  // Daten anzeigen
  client.print("<p>Die Rampe ist:   ");
  if(Arm == HIGH) {
    client.print("Bereit</p>");
  } else {
    client.print("NICHT Bereit</p>");
  }
  client.print("<p>Der Druck ist: ");
  
  // njax Daten hier
  client.println("<span id=\"DHT11Vals\"></span>");


  client.println("</html>");
  client.println("<script>setInterval(function(){getDHT11Vals();}, 250);  function getDHT11Vals(){var DHT11Request = new XMLHttpRequest();DHT11Request.onreadystatechange = function() { if(this.readyState == 4 && this.status == 200 && this.responseText != null){document.getElementById(\"DHT11Vals\").innerHTML = this.responseText;}};DHT11Request.open(\"GET\", \"readDHT11\", true);DHT11Request.send();}</script>");

  delay(1);
  if(connection_debug) Serial.println("Client trennen");
  if(connection_debug) Serial.println("");
  }
}

String getIP(){
  return (WiFi.localIP().toString());
}