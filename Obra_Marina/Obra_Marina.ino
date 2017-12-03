// testing a stepper motor with a Pololu A4988 driver board or equivalent
// on an Uno the onboard led will flash with each step
// this version uses delay() to manage timing

byte directionPin = 2;
byte stepPin = 3;
byte directionPin_2 = 4;
byte stepPin_2 = 5;
int numberOfSteps = 200;
byte ledPin = 13;
int pulseWidthMicros = 10000;  // microseconds
int pulseWidthMicros_2 = 10000;  // microseconds


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
 digitalWrite(directionPin_2, HIGH);

  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin_2, HIGH);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin_2, LOW);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
  }
  delay(1000);
 digitalWrite(directionPin, LOW);
 digitalWrite(directionPin_2, LOW);

  for(int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin_2, HIGH);
    delayMicroseconds(pulseWidthMicros_2); // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin_2, LOW);
    delayMicroseconds(pulseWidthMicros_2); // this line is probably unnecessary
  }
  
}
