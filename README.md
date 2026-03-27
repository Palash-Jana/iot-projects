# 📡 ESP32 Setup and Configuration Guide

This guide provides step-by-step instructions to set up **Arduino IDE**, install **ESP32 drivers**, configure **ESP32 board**, select **COM port**, and set up **Email Alerts** and **Telegram Bot messaging** for ESP32 projects.

# 1️⃣ Download and Install Arduino IDE

### Step 1: Download Arduino IDE
* Go to the official Arduino website:
* 🔗 [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
* Download **Arduino IDE 2.x (Windows/Linux/Mac)**

### Step 2: Install Arduino IDE
1. Open downloaded file
2. Click **Next**
3. Accept license
4. Click **Install**
5. Finish installation

### Step 3: Open Arduino IDE
After installation, launch Arduino IDE.

# 2️⃣ Install ESP32 Drivers (CP2102 / CH340)

ESP32 requires USB to Serial drivers.

## Download Drivers

### CP2102 Driver
🔗 [https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)

### CH340 Driver
🔗 [https://sparks.gogo.co.nz/ch340.html](https://sparks.gogo.co.nz/ch340.html)

## Installation
1. Download driver
2. Extract file
3. Run setup.exe
4. Click Install
5. Restart computer

# 3️⃣ Install ESP32 Board in Arduino IDE

### Step 1: Open Arduino IDE
Go to:
```
File → Preferences
```

### Step 2: Add Board Manager URL
Paste this URL in **Additional Board Manager URLs**
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
Click **OK**

### Step 3: Install ESP32 Board
Go to:
```
Tools → Board → Boards Manager
```
Search:
```
ESP32
```
Install:
```
ESP32 by Espressif Systems
```

# 4️⃣ Select ESP32 Board
Go to:
```
Tools → Board → ESP32 Arduino
```
Select:
```
ESP32 Dev Module
```

# 5️⃣ Select COM Port

### Step 1: Connect ESP32
Connect ESP32 with USB cable

### Step 2: Go to
```
Tools → Port
```
Select:
```
COM3 / COM4 / COM5 (ESP32)
```

### If Port Not Visible
1. Check Driver
2. Change USB cable
3. Restart Arduino IDE
4. Check Device Manager
```
Ports (COM & LPT)
```

# 6️⃣ Install Required Libraries
Go to:
```
Sketch → Include Library → Manage Libraries
```
Search and install:

## Required Libraries

### WiFi Library
🔗 [https://github.com/espressif/arduino-esp32](https://github.com/espressif/arduino-esp32)

### ESP Mail Client
🔗 [https://github.com/mobizt/ESP-Mail-Client](https://github.com/mobizt/ESP-Mail-Client)

### Universal Telegram Bot
🔗 [https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot)

### ArduinoJson
🔗 [https://github.com/bblanchon/ArduinoJson](https://github.com/bblanchon/ArduinoJson)

# 7️⃣ Email Alert Setup for ESP32

ESP32 uses **SMTP Email Service**

Recommended: **Gmail**

# Step 1: Enable 2-Step Verification
Go to:
🔗 [https://myaccount.google.com/security](https://myaccount.google.com/security)
Enable:
```
2-Step Verification
```

# Step 2: Generate App Password
Go to:
🔗 [https://myaccount.google.com/apppasswords](https://myaccount.google.com/apppasswords)
Select:
```
App → Mail
Device → Other
```
Generate Password

Example:
```
abcd efgh ijkl mnop
```

# Step 3: Use in ESP32 Code
```cpp
#define EMAIL_SENDER "your_email@gmail.com"
#define EMAIL_PASSWORD "abcd efgh ijkl mnop"
#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT 465
#define EMAIL_RECIPIENT "receiver@gmail.com"
```

# Important
Use **App Password**, not Gmail password.

# 8️⃣ Telegram Bot Setup for ESP32

ESP32 can send messages using Telegram Bot.

# Step 1: Open Telegram
Search:
```
BotFather
```
Or open:
🔗 [https://t.me/BotFather](https://t.me/BotFather)

# Step 2: Create New Bot
Send:
```
/start
```
Then:
```
/newbot
```
Enter:
```
Bot Name
```
Example:
```
Drone Alert Bot
```
Enter:
```
Username
```
Example:
```
drone_alert_bot
```

# Step 3: Get Bot Token
BotFather will give:
```
123456789:AAHsdjfhskdfhskdfhskdf
```
Save this token.

# Step 4: Get Chat ID
Open Telegram and search:
```
userinfobot
```
Or open:
🔗 [https://t.me/userinfobot](https://t.me/userinfobot)
Send:
```
/start
```
You will get:
```
Chat ID: 123456789
```

# Step 5: Use in ESP32 Code
```cpp
#define BOT_TOKEN "123456789:AAHsdjfhskdfhskdfh"
#define CHAT_ID "123456789"
```

# 9️⃣ Install Telegram Library in Arduino
Go to:
```
Sketch → Include Library → Manage Libraries
```
Search:
```
Universal Telegram Bot
```
Install.

# 🔟 Upload Code to ESP32

### Steps
1. Connect ESP32
2. Select Board
3. Select COM Port
4. Click Upload
5. Press Boot Button if needed

Upload → Done

# 11️⃣ Serial Monitor
Open:
```
Tools → Serial Monitor
```
Set:
```
Baud Rate: 115200
```
You will see:
```
WiFi Connected
Email Sent
Telegram Message Sent
```

# ✅ Setup Completed

Now ESP32 will:
* Connect to WiFi
* Send Email Alerts
* Send Telegram Messages
* Work with Arduino IDE

# 📌 Required Tools Summary

| Tool                 | Link                                                                                                                                 |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| Arduino IDE          | [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)                                                             |
| ESP32 Board          | [https://github.com/espressif/arduino-esp32](https://github.com/espressif/arduino-esp32)                                             |
| CP2102 Driver        | [https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) |
| CH340 Driver         | [https://sparks.gogo.co.nz/ch340.html](https://sparks.gogo.co.nz/ch340.html)                                                         |
| ESP Mail Client      | [https://github.com/mobizt/ESP-Mail-Client](https://github.com/mobizt/ESP-Mail-Client)                                               |
| Telegram Bot Library | [https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot)     |
| ArduinoJson          | [https://github.com/bblanchon/ArduinoJson](https://github.com/bblanchon/ArduinoJson)                                                 |

