#define TRIG_PIN 7  // Ultrasonic sensor trigger pin
#define ECHO_PIN 8  // Ultrasonic sensor echo pin
#define LED_PIN 13  // LED pin

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
    long duration;
    float distance;

    // Send a 10µs HIGH pulse to trigger the sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure the time it takes for the echo to return
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convert time to distance (cm)
    distance = (duration * 0.0343) / 2;

    // If movement is detected within 50cm, turn on LED and signal via serial
    if (distance > 0 && distance < 50) {  
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Movement Detected");  // Send signal to computer with newline
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    delay(100);  // Small delay to prevent excessive readings
}


