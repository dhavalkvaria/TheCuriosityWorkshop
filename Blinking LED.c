// Define the pin number where the LED is connected
int led = 8;  

// The setup function runs once when the board is powered on or reset
void setup() {
  pinMode(led, OUTPUT);  // Set the LED pin as an output
}

// The loop function runs continuously
void loop() {
  digitalWrite(led, HIGH);  // Turn the LED ON
  delay(1000);              // Wait for 1 second (1000 milliseconds)
  
  digitalWrite(led, LOW);   // Turn the LED OFF
  delay(1000);              // Wait for 1 second (1000 milliseconds)
}
