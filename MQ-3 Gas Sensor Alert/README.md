---

# � ESP32 MQ-3 Gas Sensor Email Alert System

This project uses an **ESP32 microcontroller** and **MQ-3 Gas Sensor** to detect alcohol/gas levels and send **real-time Email alerts** when the gas level crosses a defined threshold.

The ESP32 connects to WiFi, reads MQ-3 sensor data, and sends alerts using **Gmail SMTP**.

---

# 📌 Features

* ESP32 WiFi connectivity
* MQ-3 Alcohol/Gas detection
* Real-time sensor monitoring
* Email alert system
* Threshold-based alert
* Serial monitor logging
* Easy wiring and setup
* Secure authentication

---

# 🧰 Components Required

| Component             | Quantity |
| --------------------- | -------- |
| ESP32 Dev Board       | 1        |
| MQ-3 Gas Sensor       | 1        |
| Jumper Wires          | 3        |
| USB Cable             | 1        |
| Breadboard (Optional) | 1        |

---

# 🔌 Wiring Diagram

## Connection Table

| MQ-3 Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 5V        |
| GND      | GND       |
| AO       | GPIO34    |

---

# ⚙️ Arduino IDE Setup

## Step 1: Install Arduino IDE

Download:

[https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

Install Arduino IDE.

---

## Step 2: Install ESP32 Board

Go to:

```
File → Preferences
```

Paste:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Then:

```
Tools → Board → Boards Manager
```

Search:

```
ESP32
```

Install **ESP32 by Espressif Systems**

---

# 📚 Required Libraries

Install from Arduino Library Manager.

## 1️⃣ ESP Mail Client

[https://github.com/mobizt/ESP-Mail-Client](https://github.com/mobizt/ESP-Mail-Client)

## 2️⃣ WiFi

Already included with ESP32 board.

---

# 📡 WiFi Setup

Replace in code:

```cpp
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
```

Example:

```cpp
#define WIFI_SSID "JioFiber"
#define WIFI_PASSWORD "12345678"
```

---

# 📧 Email Alert Setup

ESP32 uses **Gmail SMTP**.

---

## Step 1: Enable 2-Step Verification

[https://myaccount.google.com/security](https://myaccount.google.com/security)

Enable:

```
2-Step Verification
```

---

## Step 2: Generate App Password

[https://myaccount.google.com/apppasswords](https://myaccount.google.com/apppasswords)

Select:

```
Mail
Other
```

Generate password.

Example:

```
abcd efgh ijkl mnop
```

---

## Step 3: Add in Code

```cpp
#define AUTHOR_EMAIL "your_email@gmail.com"
#define AUTHOR_PASSWORD "abcd efgh ijkl mnop"
#define RECIPIENT_EMAIL "receiver@gmail.com"
```

---

---

# 🧪 MQ-3 Sensor Working

MQ-3 detects:

* Alcohol
* Smoke
* Gas
* Chemical vapors

Output:

```
Analog voltage
```

ESP32 reads:

```
0 – 4095
```

---

# 🎯 Threshold Setting

In code:

```cpp
int gasThreshold = 2000;
```

| Value | Sensitivity |
| ----- | ----------- |
| 1500  | Low         |
| 2000  | Medium      |
| 2500  | High        |

---

# 🚀 Upload Code

## Step 1

Connect ESP32

## Step 2

Select board

```
ESP32 Dev Module
```

## Step 3

Select COM port

```
Tools → Port → COM3
```

## Step 4

Click Upload

---

# 🖥 Serial Monitor Output

```
Connecting to WiFi...
WiFi Connected
MQ3 Value: 1450
MQ3 Value: 2350
Gas Detected
Sending Email...
Sending Telegram...
Alert Sent
```

---

# 📧 Email Alert Example

**Subject**

```
MQ-3 Gas Alert
```

**Message**

```
Warning!
Gas Level High
Sensor Value: 2350
```

---

# 📲 Telegram Alert Example

```
⚠️ MQ-3 Gas Alert
Gas Level High
Sensor Value: 2350
```

---

# ⏱ MQ-3 Warmup Time

Important:

```
30–60 seconds required
```

for stable readings.

---

# 📁 Project Structure

```
MQ3_Gas_Alert/
│
├── MQ3_Email_Alert.ino
├── MQ3_Telegram_Alert.ino
├── wiring_diagram.png
├── README.md
└── LICENSE
```

---

# 🔐 Security Note

Do not upload:

```
WiFi password
Email password
Bot token
App password
```

Use:

```
config.h
```

or environment file.

---

# 🛠 Troubleshooting

## WiFi Not Connecting

* Check SSID
* Check password
* Restart ESP32

---

## Email Not Sending

* Enable App Password
* Check SMTP
* Check internet

---

## Telegram Not Working

* Check bot token
* Check chat ID
* Install libraries
* Use secure client

---

---

# 📜 License

This project is open-source and free for educational and research use.

---

# 👨‍💻 Author

**Palash Jana**
B.Tech CSE | ESP32 IoT Developer

GitHub:
[https://github.com/Palash-Jana](https://github.com/Palash-Jana)

---

