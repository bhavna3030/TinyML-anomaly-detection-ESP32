#include <esp32_anomaly_detection_inferencing.h>
#include <Wire.h>

#define CONVERT_G_TO_MS2 9.80665f
#define LED_PIN 2

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    Wire.begin(21, 22);
    Wire.beginTransmission(0x68);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
    Serial.println("Edge Impulse Anomaly Detection");
}

void loop() {
    float buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];
    
    for(int i = 0; i < EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE; i += 3) {
        Wire.beginTransmission(0x68);
        Wire.write(0x3B);
        Wire.endTransmission(false);
        Wire.requestFrom(0x68, 6, true);
        
        buffer[i]   = (Wire.read() << 8 | Wire.read()) / 16384.0f * CONVERT_G_TO_MS2;
        buffer[i+1] = (Wire.read() << 8 | Wire.read()) / 16384.0f * CONVERT_G_TO_MS2;
        buffer[i+2] = (Wire.read() << 8 | Wire.read()) / 16384.0f * CONVERT_G_TO_MS2;
        
        delay(10);
    }
    
    signal_t signal;
    numpy::signal_from_buffer(buffer, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);
    
    ei_impulse_result_t result;
    run_classifier(&signal, &result, false);
    
    Serial.print("Anomaly score: ");
    Serial.println(result.anomaly);
    
    if(result.anomaly > 25) {
        Serial.println("ANOMALY DETECTED!");
        // Blink LED rapidly 5 times
        for(int i = 0; i < 3; i++) {
            digitalWrite(LED_PIN, HIGH);
            delay(50);
            digitalWrite(LED_PIN, LOW);
            delay(50);
        }
    } else {
        Serial.println("Normal");
        digitalWrite(LED_PIN, LOW);
    }
}
