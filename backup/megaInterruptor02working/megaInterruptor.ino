  const int pin2 = A2; // pin 2 on the DB25 corresponds to pin A2 on Arduino Mega 
  const int pin1 = 7; //pin 1 on the DB25 corresponds to pin 7 on Arduino Mega
  const int pin8 = 8; //pin 8 on the DB25 corresponds to pin 8 on Arduino Mega
  const int pin14 = 2; //pin 14 on the DB25 corresponds to pin 2 on Arduino Mega
  const int temp_pin15 = 11; //pin 15 on the DB25 TEMPORARILY connected to pin 11 of Arduino Mega
  const int pin16 = 3; //pin 16 on the DB25 corresponds to pin 3 on Arduino Mega
  const int pin20 = 4; //pin 20 on the DB25 corresponds to pin 4 on Arduino Mega
  const int pin22 = 5; //pin 22 on the DB25 corresponds to pin 5 on Arduino Mega
  double rf_lim = 120.0;
  int state_pin11 = 0;
  int powerLevel_pin24 = 0;
  int forwardPower_pin3 = 0;
  int reversePower_pin2 = 0;
  double forwardPower_watts = 0;
  double reversePower_watts = 0;
  

// the setup function runs once when you press reset or power the board
void setup() {

   Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(pin1, INPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin14, OUTPUT);
  pinMode(temp_pin15, OUTPUT);
  pinMode(pin16, OUTPUT);
  pinMode(pin20, OUTPUT);
  pinMode(pin22, OUTPUT);
  pinMode(A5, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin8, HIGH); // RF enable HIGH
  digitalWrite(temp_pin15, HIGH); // BURST always ON (constant output)
  digitalWrite(pin14, LOW); // Blanking off
  digitalWrite(pin16, HIGH); // Burst Mode on
  digitalWrite(pin20, HIGH); // LOAD power leveling
  digitalWrite(pin22, LOW); // LOAD power leveling
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW 
  state_pin11 = digitalRead(A5); 
  powerLevel_pin24 = analogRead(A1);
  forwardPower_pin3 = analogRead(A3);
  reversePower_watts = rf_lim * double(analogRead(pin2)) / 1024.0;
  forwardPower_watts = rf_lim * double(forwardPower_pin3) / 1024.0;
  Serial.print("forw_pow = ");
  Serial.print(forwardPower_watts); 
  Serial.print(" rev_pow = ");
  Serial.print(reversePower_watts); 
  Serial.println();                  
}
