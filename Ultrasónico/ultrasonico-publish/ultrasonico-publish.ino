#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/
// NO BORRAR
#define WLAN_SSID       "......."
#define WLAN_PASS       "......."

/************************* Adafruit.io Setup *********************************/
// NO BORRAR
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    ".........."
#define AIO_KEY         ".........."

/************ Global State (you don't need to change this!) ******************/
//NO BORRAR
// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiClientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
// NO BORRAR
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_USERNAME, AIO_KEY);

/****************************** Feeds for Publishing***************************************/
// Setup a feed called 'ultrasonic' for publishing.
Adafruit_MQTT_Publish ultrasonic = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ultrasonico");

/****************************** Feeds for Subscribing***************************************/
// Setup a feed called 'slider' for subscribing to changes on the slider

//Adafruit_MQTT_Subscribe slider = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/slider", MQTT_QOS_1);

// Setup a feed called 'onoff' for subscribing to changes to the button

//Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff", MQTT_QOS_1);

// ****************Declaración de variables globales, para pines, datos, etc. ******************
//Ej: int ledRojo = D1;
const int trigPin = D5; //Para ESP82266 usar D5 si o si; 
const int echoPin = D6;//Para ESP82266 usar D6 si o si;

long duration = 0;
float distance = 0;

/*************************** Sketch Code ************************************/
//Callbacks, funciones para el manejo de la información obtenida en adafruit (subscribed)
void slidercallback(double x) {
  Serial.print("Hey we're in a slider callback, the slider value is: ");
  Serial.println(x);
}

void onoffcallback(char *data, uint16_t len) {
  Serial.print("Hey we're in a onoff callback, the button value is: ");
  Serial.println(data);
  String message = String(data);
  message.trim();
  if (message == "ON") {
    //Codigo si se envia ON
    digitalWrite(D0, HIGH);
  }
  if (message == "OFF") {
    //codigo si se envia OFF
    digitalWrite(D0, LOW);
  }
}

//*********************************************** SetUp *****************************/
void setup() {
  //Definicion del tipo de pines o cosas necesarias para el funcionamiento de sensores
  //Ej: pinMode(D0, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  //Iniciar la comunición Serial (NO BORRAR)
  Serial.begin(115200);

  //Delay para comenzar la conexion WIFI (NO BORRAR)
  delay(10);
  
  //****************************************** Connect to WiFi access point (NO BORRAR)
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
  
  //********************************************* Callback Functions (BORRAR SOLO SI NO SE HACE SUBSCRIBED)
  //Se setean los callbacks para las variables de subscribed
  //Sintaxis: <variableSubscribed>.setCallback(<callBack a usar>);
  
  //Ej: slider.setCallback(slidercallback);
  //Ej: onoffbutton.setCallback(onoffcallback);
  
  // Setup MQTT subscription for feed's.
  // Configurar que MQTT se suscriba a los feed creados para subscribed
  //Sintaxis: mqtt.subscribe(&<variableSuscribed>);
  
  //Ej: mqtt.subscribe(&slider);
  //Ej: mqtt.subscribe(&onoffbutton);

}

//uint32_t x=0;

//***************************************************** Loop ********************************/
void loop() {
  //Conectar con MQTT (NO BORRAR)
  MQTT_connect();
  mqtt.processPackets(10000);
  if(! mqtt.ping()) {   // ping the server to keep the mqtt connection alive
    mqtt.disconnect();}

  //RESTO DEL CODIGO, TRABAJAR NORMAL COMO EN ARDUINO
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= (duration*0.0343)/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Now we can publish stuff!
  ultrasonic.publish(distance);
  
  //Importante este delay de 2 seg. entre medidas
  delay(2000);
}

// Function to connect and reconnect as necessary to the MQTT server.
// NO BORRAR
void MQTT_connect() {
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) {
    return;}
  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 10 seconds...");
       mqtt.disconnect();
       delay(10000);  // wait 10 seconds
       retries--;
       if (retries == 0) {       // basically die and wait for WDT to reset me
         while (1);}}
  Serial.println("MQTT Connected!");
}
