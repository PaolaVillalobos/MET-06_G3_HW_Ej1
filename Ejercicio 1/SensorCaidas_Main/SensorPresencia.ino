const int Sensor1_PIN = 14;
const int Sensor2_PIN = 2;
const int DELAY_PRESENCIA = 1000;
int SensorState1 = 0;
int SensorState2 = 0;
unsigned long lastPresencia = 0;
float ThresholdTime = sqrt(2*0.5/9.8);

void Presencia_Setup() {
  Serial.println("Loading...");
  pinMode(Sensor1_PIN, INPUT);
  pinMode(Sensor2_PIN, INPUT);

}

void Presencia_Loop() {
  SensorState1 = digitalRead(Sensor1_PIN);
  SensorState2 = digitalRead(Sensor2_PIN);

  if ((millis() - lastPresencia) > DELAY_PRESENCIA) { 
    lastPresencia=millis();
    if(SensorState1 == HIGH){
      delay(ThresholdTime);
      Serial.println("PRESENCIA sensor 1");
      if(SensorState2 == HIGH){
        Serial.println("PRESENCIA sensor 2");
      }
    }
  }
  

}