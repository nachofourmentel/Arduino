
#include <MIDI.h>

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0; 

const int InputCount = 1;
int note[InputCount] = {60};

void setup() {
 MIDI.begin(1); 
 pinMode(sensorPin, INPUT);
 Serial.begin(115200); 
}

void loop() {
 delay(50); 
 sensorValue = analogRead(sensorPin);    
 byte velocity = map(sensorValue, 0, 1023, 60, 127);
      if (sensorValue > 600){
  MIDI.sendNoteOn(note[0], velocity, 1);
  delay(100);
  MIDI.sendNoteOff(note[0], 0, 1);
      }  
//  MIDI.sendNoteOff(note[0], 0, 1);
//  MIDI.sendNoteOn(note[1], velocity, 1);
//  delay(100);

//    MIDI.sendNoteOn(note[2], velocity, 1);
//  delay(100);
//  MIDI.sendNoteOff(note[2], 0, 1);
}
