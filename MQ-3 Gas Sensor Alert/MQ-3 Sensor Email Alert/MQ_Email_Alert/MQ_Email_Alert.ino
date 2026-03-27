//This code is Crteate by Palash Jana
// This code sends gas sensor data via email
#include <WiFi.h>
#include <ESP_Mail_Client.h>

// WiFi credentials
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// Email credentials
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

#define AUTHOR_EMAIL "your_email@gmail.com"
#define AUTHOR_PASSWORD "your_app_password"

#define RECIPIENT_EMAIL "receiver_email@gmail.com"

// MQ3 sensor pin
#define MQ3_PIN 34// please select your pin which you use

// Gas threshold
int gasThreshold = 2000;

// SMTP object
SMTPSession smtp;

// Email session
ESP_Mail_Session session;

// Email message
SMTP_Message message;

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

  // SMTP server configuration
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = "";

  // Email message setup
  message.sender.name = "ESP32 MQ3 Alert";
  message.sender.email = AUTHOR_EMAIL;
  message.subject = "MQ-3 Gas Alert";
  message.addRecipient("User", RECIPIENT_EMAIL);

  message.text.content = "MQ-3 Gas detected!";
  message.text.charSet = "us-ascii";
  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
}

void loop()
{
  int gasValue = analogRead(MQ3_PIN);

  Serial.print("MQ3 Value: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold)
  {
    Serial.println("Gas Detected! Sending Email...");

    message.text.content = "Warning!\nMQ-3 Gas Level High\nSensor Value: " + String(gasValue);

    if (!smtp.connect(&session))
    {
      Serial.println("SMTP Connection Failed");
      return;
    }

    if (!MailClient.sendMail(&smtp, &message))
    {
      Serial.println("Email Send Failed");
      Serial.println(smtp.errorReason());
    }
    else
    {
      Serial.println("Email Sent Successfully");
    }

    smtp.closeSession();

    delay(15000);
  }

  delay(2000);
}