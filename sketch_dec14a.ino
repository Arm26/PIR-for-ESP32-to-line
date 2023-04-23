#include <WiFi.h>
#include <WiFiClientSecure.h>
const char* ssid = "Arm26";
const char* password = "2612380011";

String txt1 = "มีคนอยู่ในรถ";
int sensorPin = 13;
int LED1_PIN = 32;
int SPK1 = 33;
int val = 0;
int in = 17;
int en = 16;
bool motionState = false;
void setup()
{
pinMode(sensorPin, INPUT);
pinMode(LED1_PIN, OUTPUT);
pinMode(SPK1, OUTPUT);
pinMode(in,OUTPUT);
pinMode(en,OUTPUT);
digitalWrite(SPK1,LOW);
Serial.begin(115200);
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void loop()
{
  digitalWrite(in,HIGH);
  digitalWrite(en,HIGH);
  val = digitalRead(sensorPin);
  if (val == HIGH)
  {
    digitalWrite(LED1_PIN,HIGH);
    digitalWrite(SPK1,LOW);
    delay(150);
    if (motionState == false)
    {
      Serial.println("Motion detected!");
      motionState = true;
    }
  }
  else
  {
    digitalWrite(LED1_PIN,LOW);
    digitalWrite(SPK1,HIGH);
    delay(150);
    if (motionState == true)
    {
      Serial.println("Motion ended!");
      motionState = false;
    }
  }
}