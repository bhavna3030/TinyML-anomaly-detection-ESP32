# ESP32 TinyML Anomaly Detection

Real-time anomaly detection running entirely on ESP32 — no cloud, no internet, zero dependency.
<img width="556" height="536" alt="image" src="https://github.com/user-attachments/assets/6a998f8e-b6d6-4c5d-9b2d-6df8a3f269fe" />



## Demo
https://drive.google.com/file/d/1IDL_qp9vv_jcccaxsPYauwEpgxADsc_B/view?usp=drivesdk

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
  <img width="694" height="678" alt="image" src="https://github.com/user-attachments/assets/d361b55c-b2ef-433a-b84e-2389d5594658" />


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
  <img width="3024" height="4032" alt="IMG_5113" src="https://github.com/user-attachments/assets/692383d8-ced2-4dd2-a73c-d4d1a9c8d5a2" />
<img width="193" height="221" alt="Screenshot 2026-05-27 130551" src="https://github.com/user-attachments/assets/a4785155-bc7e-4a4c-b694-69ef11a22454" />


## Built By
ECE Graduate — Bangalore, India
Looking for AI Engineering internships in UAE and Singapore
