🚗 Vehicle Speed Detection System (Arduino + Ultrasonic Sensors)

📌 Project Overview

This project is an Arduino-based vehicle speed detection system that uses two ultrasonic sensors to calculate the speed of a moving vehicle.

The system measures the time taken for a vehicle to travel between two fixed sensor points and computes its speed.

⸻

⚙️ Components Used
	•	Arduino UNO
	•	2 × HC-SR04 Ultrasonic Sensors
	•	Buzzer (for overspeed alert)
	•	Breadboard
	•	Jumper wires

⸻

🧠 Working Principle

Sensor 1 detects the vehicle and starts the timer.
Sensor 2 detects the vehicle and stops the timer.

The distance between the two sensors is fixed, and speed is calculated using:

Speed = Distance / Time

⸻

🚨 Features
	•	Real-time speed calculation
	•	Dual ultrasonic sensor detection
	•	Overspeed warning using buzzer
	•	Arduino UNO-based implementation
	•	Simulation using Wokwi

⸻

🎥 Demo Video

The project demonstration video is included in this repository as:

demo.mp4

You can play it directly on GitHub.

⸻

🧪 Simulation

This project was developed and tested using the Wokwi Arduino Simulator.

Wokwi Project Link: (add your link here)

⸻

📂 Project Structure

vehicle-speed-detection-arduino/
├── arduino_speed_detection.ino
├── demo.mp4
├── README.md

⸻

👨‍💻 Author

Vinay Sai