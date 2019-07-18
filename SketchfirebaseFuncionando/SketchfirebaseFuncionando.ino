#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "spqce-1234.firebaseio.com"
#define FIREBASE_AUTH "J2jJs5gNZUIGmb03IK5zI05rdNqcMo6aQfGQihSX"
#define WIFI_SSID "Megacable-PQ25"
#define WIFI_PASSWORD "16688661"
#define LED_BUILTIN 2
#define Help_Led 1

void setup()
{
Serial.begin(115200);
pinMode(Help_Led, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
  delay(2000);
  Serial.println('\n');
  wifiConnect();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
  delay(10);
}
void loop()
{  
  //int base = Firebase.getString("offices\americas\wc").toInt();
    int test = Firebase.getString("offices\americas\wc");
instaLed(base);
Serial.print(base);
delay(10);
if(WiFi.status() != WL_CONNECTED)
{
  wifiConnect();
}
delay(10);
digitalWrite(LED_BUILTIN, LOW);                         // turn the LED on (HIGH is the voltage level)

}

void wifiConnect()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                   // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID); Serial.println(" ...");
  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  {                                                                   // Wait for the Wi-Fi to connect
    Serial.print(++teller); Serial.print(' ');
     delay(500); 
     digitalWrite(LED_BUILTIN, HIGH);                            // turn the LED on (HIGH is the voltage level)
     delay(500);                                                   // wait for a second
  digitalWrite(LED_BUILTIN, LOW);                              // turn the LED off by making the voltage LOW
  Serial.println(WiFi.localIP());                     // Send the IP address of the ESP8266 to the computer
  }
}
void instaLed(int base){
   if (base==1){
   digitalWrite(Help_Led, LOW);
    }else if (base==0){
      digitalWrite(Help_Led,HIGH );
      }
  }
