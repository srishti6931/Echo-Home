#include <SoftwareSerial.h>

const int whiteLED = 4;
const int redLED = 3;
const int pinkLED = 2;
const int fanRelay = 8;

String voice;       // Variable to store incoming voice command
int TxD = 11;
int RxD = 12;
SoftwareSerial bluetooth(TxD, RxD);

bool partyActive = false;
unsigned long previousMillis = 0;
int currentLED = 4; // Start with the first LED
const unsigned long interval = 250; // 250ms interval for blinking

void setup() {
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);     
  Serial.begin(9600);       
  bluetooth.begin(9600);
}
void loop() { 
  if (bluetooth.available()){
    voice = bluetooth.readString();
    voice.trim();          // Remove extra spaces or newline characters
    Serial.println(voice);

    if (voice.equalsIgnoreCase("Lights on")){
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH); 
    }
    if (voice.equalsIgnoreCase("Lights off")){
      digitalWrite(4, LOW); 
      digitalWrite(3, LOW); 
      digitalWrite(2, LOW);        
    }
    if (voice.equalsIgnoreCase("turn on white LED")){
      digitalWrite(4, HIGH); 
    }
    if (voice.equalsIgnoreCase("turn on red LED")){
      digitalWrite(3, HIGH);       
    }
    if (voice.equalsIgnoreCase("turn on pink LED")) {
      digitalWrite(2, HIGH); 
    }
    if (voice.equalsIgnoreCase("turn off white LED")){
      digitalWrite(4, LOW); 
    }
    if (voice.equalsIgnoreCase("turn off Red LED")){
      digitalWrite(3, LOW);       
    }
    if (voice.equalsIgnoreCase("turn off pink LED")) {
      digitalWrite(2, LOW);  
    }
    
    if (voice.equalsIgnoreCase("Party time")) {
      partyActive = true;
    }
    if (voice.equalsIgnoreCase("Party over")) {
      partyActive = false;
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
    }
  }
  // Handle LED blinking if party mode is active
  if (partyActive) {
    unsigned long currentMillis = millis();
    // Check if it's time to switch LEDs
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis; // Update the time
      switch (currentLED) {
        case 4:
          digitalWrite(4, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(2, LOW);
          currentLED = 3; // Next LED
          break;
        case 3:
          digitalWrite(4, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(2, LOW);
          currentLED = 2; // Next LED
          break;
        case 2:
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);
          digitalWrite(2, HIGH);
          currentLED = 4; // Loop back to the first LED
          break;
      }
    }  
  }
    if (voice.equalsIgnoreCase("turn on fan")) {
      digitalWrite(8, HIGH);
    }
    if (voice.equalsIgnoreCase("turn off fan")) {
      digitalWrite(8, LOW); 
    }
    if (voice.equalsIgnoreCase("turn on all devices")){
      digitalWrite(4, HIGH); 
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(8, HIGH);
    }
    if (voice.equalsIgnoreCase("turn off all devices")){
      digitalWrite(4, LOW); 
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      digitalWrite(8, LOW);
    }
}