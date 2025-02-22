// Code for Dancing LED using Arduino UNO

int x[] = {13, 12, 11, 10, 9, 8, 7, 6}; // Array of pin numbers connected to LEDs
int y = 0; // Variable to keep track of the current LED index
int duration = 200; // Duration for which each LED will be on (in milliseconds)

void setup() {
    // Initialize each pin in the array as an OUTPUT
    for(int i = 0; i < 8; i++) {
        pinMode(x[i], OUTPUT); // Set pin x[i] as an output pin
    }
}

void loop() {
    // Turn off all LEDs before turning on the next one
    for (int i = 0; i < 8; i++) {
        digitalWrite(x[i], LOW); // Set all pins to LOW (turn off all LEDs)
    }
    
    // Turn on the current LED based on the index y
    digitalWrite(x[y], HIGH);  // Set pin x[y] to HIGH (turn on the current LED)
    
    // Wait for the specified duration before moving to the next LED
    delay(duration); 
    
    y++;     // Move to the next LED
    
    // If the index exceeds the number of LEDs, reset it to 0
    if (y > 7) {
        y = 0; // Reset index to 0 to loop back to the first LED
    }
}