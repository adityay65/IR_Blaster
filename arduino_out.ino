#include <IRremote.hpp>

#define IR_RECEIVE_PIN 2
#define LED_PIN1 7
#define LED_PIN2 8
#define LED_PIN3 9

String receivedValue = "";
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
   pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT); // Start the receiver with NEC protocol
}

void loop() {
  if (IrReceiver.decode()) {
    // Extract the address from the decoded IR data
    unsigned int address