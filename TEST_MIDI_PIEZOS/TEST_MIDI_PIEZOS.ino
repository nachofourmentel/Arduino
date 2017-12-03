#include <MIDI.h>

const int InputCount = 4;
int piezo[InputCount] = {A0, A1, A2, A3};
int note[InputCount] = {60, 84, 48, 72};

const int threshold = 40;

void setup() {
  MIDI.begin(1);
  Serial.begin(115200); 
}

void loop() {
  int sensorReading;
  sensorReading = analogRead(piezo[0]);
  if (sensorReading >= threshold) {
    int maxPiezoVal = getMaxVal(piezo[0], sensorReading);
    byte velocity = map(maxPiezoVal, 0, 1023, 0, 127); //velocity between 50 and 127 based on max val from piezo
    MIDI.sendNoteOn(note[0], velocity, 1);
    delay(10);
    MIDI.sendNoteOff(note[0], 0, 1);
    delay(10);
  }

  sensorReading = analogRead(piezo[1]);
  if (sensorReading >= threshold) {
    int maxPiezoVal = getMaxVal(piezo[1], sensorReading);
    byte velocity = map(maxPiezoVal, 0, 1023, 0, 127); //velocity between 50 and 127 based on max val from piezo
    MIDI.sendNoteOn(note[1], velocity, 1);
    delay(10);
    MIDI.sendNoteOff(note[1], 0, 1);
    delay(10);
  }
    sensorReading = analogRead(piezo[2]);
  if (sensorReading >= threshold) {
    int maxPiezoVal = getMaxVal(piezo[2], sensorReading);
    byte velocity = map(maxPiezoVal, 0, 1023, 0, 127); //velocity between 50 and 127 based on max val from piezo
    MIDI.sendNoteOn(note[2], velocity, 1);
    delay(10);
    MIDI.sendNoteOff(note[2], 0, 1);
    delay(10);
  }
  sensorReading = analogRead(piezo[3]);
  if (sensorReading >= threshold) {
    int maxPiezoVal = getMaxVal(piezo[3], sensorReading);
    byte velocity = map(maxPiezoVal, 0, 1023, 0, 127); //velocity between 50 and 127 based on max val from piezo
    MIDI.sendNoteOn(note[3], velocity, 1);
    delay(10);
    MIDI.sendNoteOff(note[3], 0, 1);
    delay(10);
  }
}
  int getMaxVal(int pin, int lastVal) {
  int currentVal = analogRead(pin);
  while (currentVal>lastVal){
    lastVal = currentVal;
    currentVal = analogRead(pin);
  }
  return lastVal;
}

