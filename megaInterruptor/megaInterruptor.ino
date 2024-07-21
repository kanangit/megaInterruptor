  const int pin8 = 8; //pin 8 on the DB25 corresponds to pin 8 on Arduino Mega
  

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pin8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin8, HIGH); // RF enable HIGH
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(15);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(15);                      // wait for a second
}
