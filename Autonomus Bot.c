// Code for Autonomus Bot using Arduino UNO

// Define L298D pins
#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10

void setup() {

  // Set all pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Optional: Start serial for debugging
  Serial.begin(9600);
}

// Function to move both motors forward
void forward(int speedVal) {
    
  // Enable motors at 'speedVal' (0-255)
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  // IN1=HIGH, IN2=LOW => Motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // IN3=HIGH, IN4=LOW => Motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to move both motors backward
void backward(int speedVal) {
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  // IN1=LOW, IN2=HIGH => Motor A backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // IN3=LOW, IN4=HIGH => Motor B backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to stop both motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  // Move forward at half speed
  forward(128);
  delay(2000);

  // Stop
  stopMotors();
  delay(1000);

  // Move backward at half speed
  backward(128);
  delay(2000);

  // Stop
  stopMotors();
  delay(1000);
}