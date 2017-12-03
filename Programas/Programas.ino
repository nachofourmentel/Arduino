
int relay = 13;

void setup() {
  // put your setup code here, to run once:
digitalWrite(relay, LOW);
}

void loop() {
 delay(5000);
 digitalWrite(relay, HIGH);
 delay(5000);
 digitalWrite(relay, LOW);
}
