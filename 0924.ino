void setup() {
  // initialize digital pin as an output.
  pinMode(3, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(3, LOW);// turn the RED LED on
    digitalWrite(6, LOW);// turn the RED LED on
  delay(1000);// wait for a second
   digitalWrite(8, LOW);// turn the RED LED on
    digitalWrite(6, LOW);// turn the RED LED on
  delay(1000);// wait for a second
  digitalWrite(3, HIGH);// turn the RED LED off
  digitalWrite(8, HIGH);// turn the RED LED off
  delay(1000);// wait for a second
  
}
