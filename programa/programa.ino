// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN_2  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
long distancia;
long distancia_2;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void loop() {
  delay(500);                      
  unsigned int uS = sonar.ping(); 
  unsigned int uS_2 = sonar_2.ping(); 
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); 
  distancia = (uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  Serial.print("Ping 2: ");
  Serial.print(uS_2 / US_ROUNDTRIP_CM); 
  distancia_2 = (uS_2 / US_ROUNDTRIP_CM);
  Serial.println("cm");
  if (distancia && distancia_2 > 100) {digitalWrite(9, LOW);}
  if (distancia && distancia_2 < 50) {digitalWrite(9,HIGH);}
}
