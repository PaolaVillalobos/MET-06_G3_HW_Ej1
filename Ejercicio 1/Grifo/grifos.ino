#include <Servo.h>

Servo Grifo;  //create servo object to control a servo

const int ServoPin = 5; //lo tenia en la 15

const int buttonServoPin = 13;  //pin del pulsador que regula el servo
bool buttonServoState = HIGH;     //estado del pulsador que regula el servo
bool lastbuttonServoState = HIGH;
const int buttonServoEmergencyPin = 12;    //pin pulsador emergencia
bool buttonServoEmergencyState = HIGH;    //estado pulsador emergencia
bool lastbuttonServoEmergencyState = HIGH;
int servoPos = 0;
int servoMode = 0;

const int ledYELLOW = 16; 

unsigned long lastDebounceTimeSmart1 = 0;
unsigned long lastDebounceTimeSmart2 = 0;
const int DEBOUNCE_DELAY_SMART = 50;

void Grifo_setup() {
  Grifo.attach(ServoPin);                           // attaches the servo to SERVOPIN
  pinMode(buttonServoPin, INPUT_PULLUP);
  pinMode(buttonServoEmergencyPin, INPUT_PULLUP);
  pinMode(ledYELLOW, OUTPUT);
}

void Grifo_loop() {
  
  bool reading = digitalRead(buttonServoPin);
  bool reading2 = digitalRead(buttonServoEmergencyPin);

  
  
  if (lastbuttonServoEmergencyState != reading) {
    lastDebounceTimeSmart1 = millis();
  }

  if ((millis() - lastDebounceTimeSmart1) > DEBOUNCE_DELAY_SMART) { 
    
    if (buttonServoEmergencyState != reading2) {
      buttonServoEmergencyState = reading2;
      if(buttonServoEmergencyState == HIGH) {       
         
          servoMode = 0;
          analogWrite(ledYELLOW, 100);
          Serial.println("EMERGENCY");
          return;
      }
    }
  }
  lastbuttonServoEmergencyState = reading;

  if (lastbuttonServoState != reading) {
    lastDebounceTimeSmart2 = millis();
  }
  if ((millis() - lastDebounceTimeSmart2) > DEBOUNCE_DELAY_SMART) { 
    
    if (buttonServoState != reading) {
      buttonServoState = reading;
      if(buttonServoState == HIGH) {
        
        servoMode++;
        if (servoMode > 2) {
          servoMode = 0;
        }
      }
    }
  }
  lastbuttonServoState = reading;

  switch (servoMode) {
    case 0:                          //GRIFO CERRADO
      servoPos = 90;
      analogWrite(ledYELLOW, 0);
      break;
    case 1:                           //GRIFO CAUDAL MEDIO
      servoPos = 180;
      analogWrite(ledYELLOW, 125);
      delay(50);
      analogWrite(ledYELLOW, 0);
      delay(50);
      break;
    case 2:                           //GRIFO CAUDAL ALTO
      servoPos = 0;
      analogWrite(ledYELLOW, 255);
      delay(25);
      analogWrite(ledYELLOW, 0);
      delay(25);
      break;
  }

  Grifo.write(servoPos);
  delay(15);
  
}