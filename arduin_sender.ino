/*
 * SimpleSender.cpp
 *
 *  Demonstrates sending IR codes in standard format with address and command
 *  An extended example for sending can be found as SendDemo.
 *
 *  Copyright (C) 2020-2022  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 *
 *  MIT License
 */
 
#include <Arduino.h>
String receivedString = ""; // Variable to store received string
#if !defined(ARDUINO_ESP32C3_DEV) // This is due to a bug in RISC-V compiler, which requires unused function sections :-(.
#define DISABLE_CODE_FOR_RECEIVER // Disables static receiver code like receive timer ISR handler and static IRReceiver and irparams data. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not required.
#endif
//#define SEND_PWM_BY_TIMER         // Disable carrier PWM generation in software and use (restricted) hardware PWM.
//#define USE_NO_SEND_PWM           // Use no carrier PWM, just simulate an active low receiver signal. Overrides SEND_PWM_BY_TIMER definition

/*
 * This include defines the actual pin number for pins like IR_RECEIVE_PIN, IR_SEND_PIN for many different boards and architectures
 */
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> // include the library

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " _FILE_ " from " _DATE_ "\r\nUsing library version " VERSION_IRREMOTE));
    Serial.print(F("Send IR signals at pin "));
    Serial.println(IR_SEND_PIN);

    /*
     * The IR library setup. That's all!
     */
    IrSender.begin(); // Start with IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin and enable feedback LED at default feedback LED pin
    disableLEDFeedback(); // Disable feedback LED at default feedback LED pin
}

/*
 * Set up the data to be sent.
 * For most protocols, the data is build up with a constant 8 (or 16 byte) address
 * and a variable 8 bit command.
 * There are exceptions like Sony and Denon, which have 5 bit address.
 */
uint8_t sCommand = 0x17;
uint8_t sRepeats = 0;
uint64_t a ;
int i ;
void loop() {
    /*
     * Print current send values
     */
      while (Serial.available() > 0) { // Check if data is available to read
        
    char receivedChar = Serial.read(); // Read the incoming byte

    if(receivedChar == '%')
    break;
    
    receivedString += receivedChar; // Append the character to the received string
    delay(2); // Allow time for the serial buffer to fill
  }
  
  if (receivedString.length() > 0) { // Check if a complete string is received
    // Print the received string to the serial monitor
    Serial.print("Received string: ");
    Serial.println(receivedString);
    
    // Do something with the received string here
    
    
    //Serial.print(F("Send now: address=0x00, command=0x"));
   // Serial.print(sCommand, HEX);
   // Serial.print(F(", repeats="));
   // Serial.print(sRepeats);
   // Serial.println();
  }
  //  Serial.println(F("Send standard NEC with 8 bit address"));
    //Serial.flush();

//    if(i==1)e3
  //  a=0x4587;

  //  else if(i==0)
    char a = receivedString[13];
    char b = receivedString[23];
    Serial.println(a);
    Serial.println(b);
    uint16_t addr=0x4554;
   if((a=='1') && (b=='n')) {addr = 0x4571; Serial.print(addr);}
   else if (a=='1' && b=='f') addr = 0x4561;
   else if (a=='2' && b=='n') addr = 0x4572;
   else if (a=='2' && b=='f') addr = 0x4562;
   else if (a=='3' && b=='n') addr = 0x4573;
   else if (a=='3' && b=='f') addr = 0x14563;
   
   receivedString = ""; // Clear the received string for the next input

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(addr, sCommand, sRepeats);

    /*
     * Increment send values
     */
    sCommand += 0x11;
    sRepeats++;
    // clip repeats at 4
    if (sRepeats > 4) {               
        sRepeats = 4;
    }

    delay(1000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}