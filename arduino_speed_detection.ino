#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5
#define buzzer 8   // optional

long time1 = 0;
long time2 = 0;

float distanceBetweenSensors = 0.1; // 10 cm
float speedLimit = 0.1; // adjust as needed

void setup() {
  Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(buzzer, OUTPUT);
}

long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  long d1 = getDistance(trig1, echo1);

  
  if (d1 < 20) {
    Serial.println("🚗 Vehicle detected at Sensor 1");
    time1 = millis();

    
    unsigned long startWait = millis();
    bool detected = false;

    while (millis() - startWait < 5000) {
      long d2 = getDistance(trig2, echo2);
      if (d2 < 20) {
        detected = true;
        break;
      }
    }

    if (detected) {
      time2 = millis();
      float timeTaken = (time2 - time1) / 1000.0;

     
      if (timeTaken > 0.01) {
        float speed = distanceBetweenSensors / timeTaken;

        Serial.println("------ RESULT ------");
        Serial.print("Time Taken: ");
        Serial.print(timeTaken);
        Serial.println(" sec");

        Serial.print("Speed: ");
        Serial.print(speed);
        Serial.println(" m/s");

        
        if (speed > speedLimit) {
          Serial.println("⚠️ OVER SPEED!");
          digitalWrite(buzzer, HIGH);
        } else {
          Serial.println("✅ Normal Speed");
          digitalWrite(buzzer, LOW);
        }

        Serial.println("--------------------");
      } else {
        Serial.println("⚠️ Ignored: Too fast");
      }

    } else {
      Serial.println("❌ Sensor 2 not triggered");
    }

    // 🛑 WAIT until vehicle leaves Sensor 1
    while (getDistance(trig1, echo1) < 20);

    delay(1000); // small buffer
  }
}