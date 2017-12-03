int rele = 7;
void setup() {
  // put your setup code here, to run once:
pinMode(rele, OUTPUT);
digitalWrite(7,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
digitalWrite(rele,LOW);
delay(1000);
digitalWrite(rele,HIGH);


}
