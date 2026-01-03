// -------- BLYNK TEMPLATE DETAILS (REQUIRED FOR BLYNK 2.0) --------
#define BLYNK_TEMPLATE_ID "TMPL3QGceyXSn"
#define BLYNK_TEMPLATE_NAME "Home Automation Relay Test"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// -------- BLYNK DETAILS --------
char auth[] = "elcQI5MAmQMqdpLb93bFyrFB4o5pg6WG";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// -------- RELAY PINS --------
#define RELAY1 26   // LED 1
#define RELAY2 27   // LED 2
#define RELAY3 14   // FAN
#define RELAY4 12   // OTHERS

// -------- RELAY 1 : LED 1 --------
BLYNK_WRITE(V0)
{
  int value = param.asInt();
  digitalWrite(RELAY1, value ? LOW : HIGH);   // LOW = ON
  Serial.println(value ? "Relay 1 (LED 1) : ON" : "Relay 1 (LED 1) : OFF");
}

// -------- RELAY 2 : LED 2 --------
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  digitalWrite(RELAY2, value ? LOW : HIGH);
  Serial.println(value ? "Relay 2 (LED 2) : ON" : "Relay 2 (LED 2) : OFF");
}

// -------- RELAY 3 : FAN --------
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  digitalWrite(RELAY3, value ? LOW : HIGH);
  Serial.println(value ? "Relay 3 (FAN) : ON" : "Relay 3 (FAN) : OFF");
}

// -------- RELAY 4 : OTHERS --------
BLYNK_WRITE(V3)
{
  int value = param.asInt();
  digitalWrite(RELAY4, value ? LOW : HIGH);
  Serial.println(value ? "Relay 4 (OTHERS) : ON" : "Relay 4 (OTHERS) : OFF");
}

void setup()
{
  Serial.begin(9600);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // Turn all relays OFF initially
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);

  Serial.println("Home Automation System Started...");
  Serial.println("Connecting to WiFi and Blynk...");

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
