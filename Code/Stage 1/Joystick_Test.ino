// // --- MOTOR DRIVER PINS (L298N or similar) ---
// // Pins 27 and 26 control direction
// // Pin 14 is the Enable pin (used for PWM speed control)
// int motor1Pin1 = 27;
// int motor1Pin2 = 26;
// int enable1Pin = 14;

// // --- JOYSTICK PINS ---
// // VRY (Y-axis) pin is used for speed and direction control.
// const int yPin = 35;    // VRY pin

// // --- PWM CONFIGURATION (for ESP32 LEDC Peripheral) ---
// const int freq = 30000;    // PWM frequency (30kHz is good for motors)
// const int pwmChannel = 0;  // Use channel 0
// const int resolution = 8;  // 8-bit resolution (0-255)

// // --- VARIABLES ---
// int yValue = 0;      // Stores the analog value from the Y-axis (0 - 4095)
// int motorSpeed = 200;  // The calculated PWM duty cycle (0 - 255)

// // --- DEADZONE SETTINGS ---
// // ESP32 ADC is 12-bit (0-4095). Center is around 2048.
// // We define a range around the center to force the motor to stop.
// const int CENTER_THRESHOLD_HIGH = 2200; // Joystick value above this means FORWARD
// const int CENTER_THRESHOLD_LOW = 1900;  // Joystick value below this means REVERSE

// void setup() {
//   // --- Serial Communication ---
//   Serial.begin(115200);
//   delay(100);
//   Serial.println("ESP32 Motor Control Ready.");

//   // --- Motor Pin Setup ---
//   pinMode(motor1Pin1, OUTPUT);
//   pinMode(motor1Pin2, OUTPUT);
//   pinMode(enable1Pin, OUTPUT);

//   // --- PWM Setup ---
//   // 1. Setup PWM channel (0) with frequency and resolution
//   // ledcSetup(pwmChannel, freq, resolution);
//   // // 2. Attach the channel to the Enable pin
//   // ledcAttachPin(enable1Pin, pwmChannel);

//   ledcAttach(enable1Pin, freq, resolution);
//   ledcWrite(enable1Pin, motorSpeed);
// }

// void loop() {
//   // 1. Read the Y-axis value
//   yValue = analogRead(yPin);

//   // 2. Determine Motor State (Stop, Forward, Reverse)
//   if (yValue > CENTER_THRESHOLD_HIGH) {
//     // === FORWARD (Joystick UP) ===
//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);

//     // Map the joystick range (2200 to 4095) to the speed range (0 to 255)
//     // Pushed slightly (2200) -> slow (0). Pushed max (4095) -> full speed (255).
//     motorSpeed = map(yValue, CENTER_THRESHOLD_HIGH, 4095, 0, 255);
//     motorSpeed = constrain(motorSpeed, 0, 255); // Ensure speed is within bounds

//   } else if (yValue < CENTER_THRESHOLD_LOW) {
//     // === REVERSE (Joystick DOWN) ===
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, HIGH);

//     // Map the joystick range (1900 to 0) to the speed range (0 to 255)
//     // The range is reversed (Low end is full speed, high end is slow).
//     motorSpeed = map(yValue, CENTER_THRESHOLD_LOW, 0, 0, 255);
//     motorSpeed = constrain(motorSpeed, 0, 255);

//   } else {
//     // === STOP (Joystick in Deadband) ===
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW); // Set direction pins to LOW to stop/brake
//     motorSpeed = 0; // Set speed to zero
//   }

//   // 3. Apply the speed (PWM duty cycle)
//   ledcWrite(pwmChannel, motorSpeed);

//   // 4. Debugging Output
//   Serial.print("Y Value: ");
//   Serial.print(yValue);
//   Serial.print("\tMotor Speed (0-255): ");
//   Serial.println(motorSpeed);

//   delay(50); // Loop quickly for responsive control
// }

// --- MOTOR DRIVER PINS (L298N or similar) ---
// Pins 27 and 26 control direction
// Pin 14 is the Enable pin (used for PWM speed control)
// NOTE: These motor pins are defined but will not be used in this version.
// int motor1Pin1 = 27;
// int motor1Pin2 = 26;
// int enable1Pin = 14;

// --- JOYSTICK PINS ---
// VRY (Y-axis) pin is used for reading the input.
const int yPin = 35; // VRY pin

// // --- PWM CONFIGURATION (defined but not used in this version) ---
// const int freq = 30000;    // PWM frequency (30kHz is good for motors)
// const int pwmChannel = 0;  // Use channel 0
// const int resolution = 8;  // 8-bit resolution (0-255)

// --- VARIABLES ---
int yValue = 0; // Stores the analog value from the Y-axis (0 - 4095)
// int motorSpeed = 0;  // Not used in this version, kept for future use.

// --- DEADZONE SETTINGS (Not used in this version) ---
const int CENTER_THRESHOLD_HIGH = 2200;
const int CENTER_THRESHOLD_LOW = 1900;

void setup()
{
    // --- Serial Communication ---
    Serial.begin(115200);
    delay(100);
    Serial.println("--- Joystick Input Debug Mode ---");
    Serial.println("Move the joystick up and down. Values should range from 0 to 4095.");

    // NOTE: We don't need to configure motor pins or PWM setup for this test.
}

void loop()
{
    // 1. Read the Y-axis value (raw input)
    yValue = analogRead(yPin);

    // 2. Display the raw value
    Serial.print("Y Axis Raw Value: ");
    Serial.println(yValue);

    delay(50); // Loop quickly to see fast changes
}