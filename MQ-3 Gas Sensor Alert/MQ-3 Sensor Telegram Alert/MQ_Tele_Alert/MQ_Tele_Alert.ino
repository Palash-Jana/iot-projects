//This code is create by Palash Jana
//This code sends Telegram bot alert in your telegram account
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// WiFi Credentials
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// Telegram Bot Token
#define BOT_TOKEN "123456789:AAExampleTokenABCXYZ"// set you own generated bot token

// Chat ID
#define CHAT_ID "123456789"// set you own bot chat id


// MQ3 Sensor Pin
#define MQ3_PIN 34// Select pin as you choice

// Gas Threshold
int gasThreshold = 2000;

// Secure Client
WiFiClientSecure client;

// Telegram Bot
UniversalTelegramBot bot(BOT_TOKEN, client);

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup()
{
  Serial.begin(115200);

  pinMode(MQ3_PIN, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println("WiFi Connected");

  client.setInsecure();   // Required for HTTPS

  Serial.println("Telegram Bot Ready");
}

void loop()
{
  int gasValue = analogRead(MQ3_PIN);

  Serial.print("MQ3 Value: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold)
  {
    Serial.println("Gas Detected! Sending Telegram Message...");

    String message = "⚠️ MQ-3 Gas Alert\n";
    message += "Gas Level High\n";
    message += "Sensor Value: ";
    message += String(gasValue);

    bot.sendMessage(CHAT_ID, message, "");

    Serial.println("Telegram Message Sent");

    delay(15000);
  }

  delay(2000);
}