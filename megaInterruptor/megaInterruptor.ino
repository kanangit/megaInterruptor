  const int pin1 = 7; //pin 1 on the DB25 corresponds to pin 7 on Arduino Mega
  const int pin8 = 8; //pin 8 on the DB25 corresponds to pin 8 on Arduino Mega
  const int pin14 = 2; //pin 14 on the DB25 corresponds to pin 2 on Arduino Mega
  const int pin16 = 3; //pin 16 on the DB25 corresponds to pin 3 on Arduino Mega
  const int pin20 = 4; //pin 20 on the DB25 corresponds to pin 4 on Arduino Mega
  const int pin22 = 5; //pin 22 on the DB25 corresponds to pin 5 on Arduino Mega
  

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(pin1, INPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin14, OUTPUT);
  pinMode(pin16, OUTPUT);
  pinMode(pin20, OUTPUT);
  pinMode(pin22, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin8, HIGH); // RF enable HIGH
  digitalWrite(pin14, LOW); // Blanking off
  digitalWrite(pin16, HIGH); // Burst Mode on
  digitalWrite(pin20, HIGH); // LOAD power leveling
  digitalWrite(pin22, LOW); // LOAD power leveling
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW                      // wait for a second
}
