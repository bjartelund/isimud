#include <Arduino.h>

#define LED_BUILTIN 25
#define REED_SWITCH 12
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(REED_SWITCH,INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(REED_SWITCH) == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN,LOW);
  }
}