// testing a stepper motor with a Pololu A4988 driver board or equivalent
// on an Uno the onboard led will flash with each step
// this version uses delay() to manage timing

byte directionPin = 3;
byte stepPin = A1;
int numberOfSteps = 5000;
byte ledPin = 13;
int pulseWidthMicros = 1000;  // microseconds
int millisbetweenSteps = 10; // milliseconds - or try 1000 for slower steps


void setup() { 
  digitalWrite(ledPin, HIGH);
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() { 
 digitalWrite(directionPin, HIGH);
  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
  }
  delay(1000);
  digitalWrite(directionPin, LOW);
  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros); // probably not needed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
  }
}
