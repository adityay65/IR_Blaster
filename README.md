Project Dates: Jan 2024 - May 2024
Lab: Tinkering Lab - Dr. Basant Subba
​OVERVIEW
​This project describes a Voice Controlled IR Blaster system designed to bring smart home functionality to traditional infrared (IR) controlled devices, such as TVs, air conditioners, and stereos. By leveraging an Arduino or ESP32 microcontroller, the system integrates IR transmission with Wi-Fi-based voice command reception to enable remote control via popular smart assistants like Alexa and Google Assistant.
​The core innovation is bridging the gap between legacy IR devices and modern voice-controlled automation platforms, creating a seamless and cost-effective smart home upgrade.
​FEATURES
​Universal IR Control: Can be programmed to send IR codes for virtually any device that uses an IR remote.
​Voice Assistant Integration: Seamlessly responds to commands given through Amazon Alexa and Google Assistant.
​Wi-Fi Connectivity: Utilizes a Wi-Fi-enabled microcontroller (like the ESP32) for network and cloud communication.
​Smart Home Automation: Enables setting up routines and schedules using voice commands for devices previously limited to manual IR control.
​Modular Design: Built upon open-source hardware (Arduino/ESP32) and readily available components.
​TECHNICAL DETAILS
​HARDWARE COMPONENTS:
Microcontroller: ESP32 (Recommended) or Arduino (with an external Wi-Fi shield).
IR LED: High-power IR Emitter diode for transmitting control signals.
Transistor: NPN transistor (e.g., BC547) to drive the high-current IR LED.
Resistors: Current-limiting resistor for the IR LED and base resistor for the transistor.
Power Supply: 5V DC power supply or USB power.
​SOFTWARE AND FRAMEWORKS:
Arduino IDE: Programming the ESP32/Arduino microcontroller.
IR Remote Library: A library (e.g., IRremote library) to record and transmit IR signals.
Voice Assistant Platform: Alexa Smart Home Skill and Google Home/IFTTT integration.
MQTT/Cloud Service: Broker/service for secure communication (e.g., Adafruit IO).
​SETUP AND CONFIGURATION
​(Simplified steps)
​Wiring: Connect IR LED, transistor, and resistors to the chosen microcontroller (ESP32/Arduino).
​Software: Use the Arduino IDE to obtain IR codes and flash the main sketch with Wi-Fi/cloud credentials.
​Integration: Configure the device on the Voice Assistant platform (e.g., Alexa or Google Home) to define voice commands that trigger IR code transmission.
​FUTURE ENHANCEMENTS
​Local-Only Control: Implement control via a local web interface.
​IR Learning Mode: Add an IR receiver to allow users to "teach" the device new remote codes.
​Multi-Blaster Support: Create a network of multiple blasters.
​Integration with Home Assistant.
