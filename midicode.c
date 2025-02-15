// midi.controller
// Sends midi program change
// Aaron Lyon April 2018
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
byte patchNum = 0;
#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 3
#define LED_PIN 13

#define BUTTON_DEBOUNCE_SHORT_MS 500
#define BUTTON_DEBOUNCE_LONG_MS 500

void setup() {
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  if (digitalRead(BUTTON_PIN_1) == LOW && patchNum < 24) {
    // Next Program
    patchNum++;
    MIDI.sendProgramChange(patchNum, 1);
    delay(200);
  }
  if (digitalRead(BUTTON_PIN_2) == LOW && patchNum >= 1) {
    // Next Program
    //digitalWrite(LED_PIN, HIGH );
    patchNum--;
    MIDI.sendProgramChange(patchNum, 1);
    delay(200);
    //digitalWrite(LED_PIN, LOW );
  }
}

