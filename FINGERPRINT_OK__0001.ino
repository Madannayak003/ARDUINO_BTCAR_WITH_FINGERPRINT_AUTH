//ARDUINO CAR-VERIFICATION CREATED BY MADAN R//
//28/05/2025//

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

#define AUTH_SUCCESS_PIN 7  // Output pin to communicate authentication status
#define LED_PIN 9          // LED for authentication status

SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

bool signalActive = false; // Track the state of the signal

void setup() {
    Serial.begin(9600);
    pinMode(AUTH_SUCCESS_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    // Ensure both signal and LED are OFF initially
    digitalWrite(AUTH_SUCCESS_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    finger.begin(57600);
    if (finger.verifyPassword()) {
        Serial.println("Fingerprint sensor found!");
    } else {
        Serial.println("Fingerprint sensor not found.");
        while (1);
    }
    Serial.println("Waiting for valid fingerprint...");
}

void loop() {
    if (getFingerprintIDez()) {
        Serial.println("Authentication successful!");

        if (!signalActive) {
            // Turn ON the signal and LED
            digitalWrite(AUTH_SUCCESS_PIN, HIGH);
            digitalWrite(LED_PIN, HIGH);
            signalActive = true;
            Serial.println("Signal turned ON.");
        } else {
            // Turn OFF the signal and LED
            digitalWrite(AUTH_SUCCESS_PIN, LOW);
            digitalWrite(LED_PIN, LOW);
            signalActive = false;
            Serial.println("Signal turned OFF.");
        }

        delay(1000); // Small delay to avoid multiple toggles from a single scan
    }
}

int getFingerprintIDez() {
    uint8_t p = finger.getImage();
    if (p != FINGERPRINT_OK) return 0;

    p = finger.image2Tz();
    if (p != FINGERPRINT_OK) return 0;

    p = finger.fingerFastSearch();
    if (p != FINGERPRINT_OK) return 0;

    return 1; // Fingerprint matched
}