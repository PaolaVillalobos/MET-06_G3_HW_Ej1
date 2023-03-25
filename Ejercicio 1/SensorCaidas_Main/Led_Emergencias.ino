// the setup function runs once when you press reset or power the board
void Led_Setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(0, OUTPUT);
}

// the loop function runs over and over again forever
void Led_Loop() {
  digitalWrite(0, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(800);                      // wait for a second
  digitalWrite(0, LOW);   // turn the LED off by making the voltage LOW
  delay(800);                      // wait for a second
  digitalWrite(0, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(800);                      // wait for a second
  digitalWrite(0, LOW);   // turn the LED off by making the voltage LOW
  delay(800);                      // wait for a second  
}