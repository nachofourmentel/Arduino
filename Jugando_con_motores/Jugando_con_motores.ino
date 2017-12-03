// testing a stepper motor with a Pololu A4988 driver board or equivalent
// on an Uno the onboard led will flash with each step
// this version uses delay() to manage timing

byte directionPin = 2;
byte stepPin = 3;
byte directionPin_2 = 4;
byte stepPin_2 = 5;
int numberOfSteps = 200;
byte ledPin = 13;
int pulseWidthMicros = 175;  // microseconds
int pulseWidthMicros_2 = 50;  // microseconds
int pulseWidthMicros_3 = 150;  // microseconds
int pulseWidthMicros_4 = 800;  // microseconds

int millisbetweenSteps = 10; // milliseconds - or try 1000 for slower steps


void setup() { 
  digitalWrite(ledPin, HIGH);
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
pinMode(stepPin_2, OUTPUT);
  pinMode(directionPin_2, OUTPUT);

}

void loop() { 
 digitalWrite(directionPin, HIGH);
 
  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
  }
  delay(500);
 digitalWrite(directionPin_2, LOW);

  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin_2, HIGH);
    delayMicroseconds(pulseWidthMicros_2); // this line is probably unnecessary
    digitalWrite(stepPin_2, LOW);
    delayMicroseconds(pulseWidthMicros_2); // this line is probably unnecessary
  }
 digitalWrite(directionPin, HIGH);
 
  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros_3); // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pulseWidthMicros_2); // this line is probably unnecessary
  }
  delay(750);
 digitalWrite(directionPin_2, HIGH);

  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin_2, HIGH);
    delayMicroseconds(pulseWidthMicros_4); // this line is probably unnecessary
    digitalWrite(stepPin_2, LOW);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
  }
  delay(100);
}
