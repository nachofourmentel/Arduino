#include <NewPing.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN_2  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
long distancia;
long distancia_2;
const int InputCount = 2;
int note[InputCount] = {
  48, 67};

void setup() {
 MIDI.begin(1); 
 Serial.begin(32500); 
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 digitalWrite(9,LOW);
 digitalWrite(10,HIGH);


}

void loop() {
 delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
 digitalWrite(ECHO_PIN, LOW); 
 digitalWrite(ECHO_PIN_2, LOW);   
 unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
// Serial.print("Ping: ");
// Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
// Serial.println("cm");
 unsigned int uS_2 = sonar_2.ping(); // Send ping, get ping time in microseconds (uS).
// Serial.print("Ping_2: ");
// Serial.print(uS_2 / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
// Serial.println("cm");
 distancia_2 = (uS_2 / US_ROUNDTRIP_CM);
 distancia = (uS / US_ROUNDTRIP_CM);
 if (distancia < 50 || distancia_2 < 50 ) {
    byte velocity = map(distancia, 0, 1023, 0, 127);
    MIDI.sendNoteOn(note[0], velocity, 1);
    delay(100);
    MIDI.sendNoteOff(note[0], 0, 1);
    
 } 
 if (distancia > 60 && distancia_2 > 60 ) {
    byte velocity = map(distancia, 0, 1023, 0, 127);
    MIDI.sendNoteOn(note[1], velocity, 1);
    delay(100);
    MIDI.sendNoteOff(note[1], 0, 1);
    } 
    }
