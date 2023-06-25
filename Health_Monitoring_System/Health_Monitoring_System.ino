#include <SoftwareSerial.h>

// Define pins for sensors
const int bloodPressureSensorPin = A0;
const int sugarLevelSensorPin = A1;
const int heartbeatSensorPin = A2;

// Define variables to store sensor readings
int bloodPressureReading = 0;
int sugarLevelReading = 0;
int heartbeatReading = 0;

// Define the software serial communication pins
const int rxPin = 10;
const int txPin = 11;

// Initialize the software serial object
SoftwareSerial serialConnection(rxPin, txPin);

void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);
  serialConnection.begin(9600);
}

void loop() {
  // Read sensor values
  bloodPressureReading = analogRead(bloodPressureSensorPin);
  sugarLevelReading = analogRead(sugarLevelSensorPin);
  heartbeatReading = analogRead(heartbeatSensorPin);

  // Send data to healthcare professionals via serial communication
  serialConnection.print("Blood Pressure: ");
  serialConnection.print(bloodPressureReading);
  serialConnection.print(" Sugar Level: ");
  serialConnection.print(sugarLevelReading);
  serialConnection.print(" Heartbeat: ");
  serialConnection.println(heartbeatReading);

  // Print the data to the Arduino Serial Monitor
  Serial.print("Blood Pressure: ");
  Serial.print(bloodPressureReading);
  Serial.print(" Sugar Level: ");
  Serial.print(sugarLevelReading);
  Serial.print(" Heartbeat: ");
  Serial.println(heartbeatReading);

  delay(1000); // Delay for 1 second before the next reading
}
