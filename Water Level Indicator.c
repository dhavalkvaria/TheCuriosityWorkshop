// Code for Water Level Indicator using Arduino UNO

const int analogInPin = A0; // Pin for analog input (sensor)
const int buzzerPin = 6;    // Pin for the buzzer
int sensorValue = 0;        // Variable to store the sensor value

void setup()
{
    // Initialize pins as outputs
    pinMode(buzzerPin, OUTPUT); // Buzzer pin
    pinMode(2, OUTPUT);         // Pin 2 (Buzzer or LED 1)
    pinMode(3, OUTPUT);         // Pin 3 (Buzzer or LED 2)
    pinMode(4, OUTPUT);         // Pin 4 (Buzzer or LED 3)

    Serial.begin(9600); // Start the serial communication
}

void loop()
{
    // Read the analog sensor value
    sensorValue = analogRead(analogInPin);

    // Print the sensor value to the serial monitor
    Serial.print("sensor = ");
    Serial.println(sensorValue); // println already adds a newline

    // Check the sensor value and control the outputs
    if (sensorValue >= 100 && sensorValue <= 600)
    {
        // Turn on pin 2 and turn off others
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(buzzerPin, LOW); // Make sure the buzzer is off
        delay(100);                   // Small delay to prevent fast toggling
    }
    else if (sensorValue >= 601 && sensorValue <= 625)
    {
        // Turn on pin 3 and turn off others
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(buzzerPin, LOW); // Make sure the buzzer is off
        delay(100);                   // Small delay to prevent fast toggling
    }
    else if (sensorValue >= 626 && sensorValue <= 700)
    {
        // Turn on pin 4 and the buzzer
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    }
    else
    {
        // If sensor value is outside all specified ranges, turn off all pins
        digitalWrite(buzzerPin, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        delay(100) // Small delay to prevent fast toggling
    }
}