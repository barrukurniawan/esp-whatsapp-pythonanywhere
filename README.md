# esp-whatsapp-pythonanywhere
*Simple Security System with ESP8266 (Notification with Whatsapp messages)*

**DISCLAIMER: This software is open source and it's for educational purposes only. It should not be used for illegal activity. The author is not responsible for its use.**

**Credits:**
Barru Kurniawan ( barru.kurniawan@gmail.com ) as author

**Requirements :**

Software :
1. Twilio Account
2. Installed Arduino IDE Software
3. Installed CH340 driver

Hardware :
1. Wemos / NodeMCU / ESP8266 / ESP32
2. Photodioda sensor
3. Mini Buzzer

*The hardware (Wemos, Photodioda sensor and mini buzzer) was bought on online shopping for about Rp.34000 in total.*

**Getting Started :**
1. Download dan **install driver CH340g** at https://sparks.gogo.co.nz/assets/_site_/downloads/CH34x_Install_Windows_v3_4.zip
   Unzip the file and run the installer which you unzipped.
1. **Intall Arduinio IDE**, available at https://www.arduino.cc/en/main/software
2. Open Arduino IDE, go to File > Preferences,
   Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into the “Additional Boards Manager URLs”. 
   Then, click the “OK” button.
3. Open the Boards Manager. Go to Tools > Board > Boards Manager,
   Search esp8266, and then click install button.
4. Afterwards, make sure you have the right board selected. Go to Tools > Board,
   If you're using NodeMCU board, choose NodeMCU 1.0 or Generic ESP8266 Module, if you're using WeMos, choose WeMos.
5. Create a new **account on Twilio**, go to https://www.twilio.com/whatsapp
   *we need to send and receive WhatsApp messages via Twilio API*
6. You must have :
   - Twilio Account SID
   - Twilio Account AUTH TOKEN
   - Message Body
   - From: *Twilio number*
   - To: *Your Whatsapp number*
