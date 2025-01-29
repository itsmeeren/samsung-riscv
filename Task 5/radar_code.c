// Define pins for Ultrasonic Sensor
#define TRIG_PIN 3   // Trigger pin connected to D3
#define ECHO_PIN 4   // Echo pin connected to D4

// Define pins for LEDs
#define RED_LED_PIN 5   // Red LED connected to D5
#define GREEN_LED_PIN 6 // Green LED connected to D6

// Threshold distance (in cm) for detecting a threat
#define THRESHOLD_DISTANCE 20

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Set up the ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Set up the LED pins
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  
  // Initialize LEDs as OFF
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);  // Green LED on by default (no threat)
}

void loop() {
  // Variables to store the duration and distance
  long duration;
  int distance;
  
  // Send a pulse to the Trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the pulse duration from the Echo pin
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance in cm
  distance = duration * 0.0344 / 2;
  
  // Output the distance to the serial monitor (optional for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check the distance and turn LEDs on/off accordingly
  if (distance <= THRESHOLD_DISTANCE) {
    // Threat detected, turn on the red LED and turn off the green LED
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    // No threat detected, turn on the green LED and turn off the red LED
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }
  
  // Wait a bit before the next reading
  delay(500);  // Adjust delay as needed
}

