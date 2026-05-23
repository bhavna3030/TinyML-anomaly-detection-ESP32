# ESP32 TinyML Anomaly Detection

Real-time anomaly detection running entirely on ESP32 — no cloud, no internet, zero dependency.

## Demo
[Insert Loom video link here]

## Hardware
- ESP32 Development Board
- MPU6050 Accelerometer + Gyroscope
- 4 Jumper Wires

## What It Does
- Reads live vibration data from MPU6050 accelerometer
- Runs TinyML inference entirely on-device
- Detects anomalies in under 20ms
- LED blinks instantly on anomaly detection
- Zero cloud dependency — works offline

## Tech Stack
- Edge Impulse — data collection and model training
- TensorFlow Lite for Microcontrollers
- Spectral Analysis for feature extraction
- K-means Anomaly Detection
- Arduino IDE

## Performance
- Inference time: 19ms
- Peak RAM usage: 3KB
- Works fully offline

## How It Works
1. MPU6050 reads accelerometer data at 100Hz
2. Spectral features extracted from raw data
3. K-means model classifies as normal or anomaly
4. LED blinks and serial alert on anomaly detection

## Results
- Normal state: low anomaly scores
- Anomaly state: high scores, instant LED alert

## Built By
ECE Graduate — Bangalore, India
Looking for AI Engineering internships in UAE and Singapore
