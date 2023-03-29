const int BUTTON_PIN_SMART = 5;
const int LED_SMART = 4;

const int DEBOUNCE_DELAY_SMART = 50;
bool buttonStateSmart = HIGH;
int mode = 0; 
bool lastButtonStateSmart = HIGH;
bool LedOn=LOW;
unsigned long lastDebounceTimeSmart = 0;
float dutyCycle=0.25;
const int DELAY_SMART = 100;
unsigned long lastSMART = 0;
void SmartLight_Setup() {
  pinMode(BUTTON_PIN_SMART, INPUT_PULLUP);
  pinMode(LED_SMART, OUTPUT);
}

void SmartLight_Loop() {

  bool reading = digitalRead(BUTTON_PIN_SMART);
  
  if (reading != lastButtonStateSmart) {
    lastDebounceTimeSmart = millis();
    
  }
  if ((millis() - lastDebounceTimeSmart) > DEBOUNCE_DELAY_SMART) { 
     
    if (reading != buttonStateSmart) { // Hace que al estar presionado el boton solo salga EMERGENCIA una vez
        

      buttonStateSmart = reading;
      if (buttonStateSmart == HIGH) {
            

          // Incrementar el modo
          mode++;
          if (mode > 3) {
            mode = 0;
          }

        // Calcular el ciclo de trabajo en función del modo
        switch (mode) {
          case 0:
            dutyCycle = 0;
            Serial.println("Modo 1");
            break;
          case 1:
            dutyCycle = 0.33;
            Serial.println("Modo 2");
            break;
          case 2:
            dutyCycle = 0.66;
            Serial.println("Modo 3");
            break;
          case 3:
            dutyCycle = 1;
            Serial.println("Modo 4");
            break;
        }
      }
    }
  
  }
   lastButtonStateSmart = reading;     

  if(LedOn==HIGH){
    if ((millis() - lastSMART) > round(DELAY_SMART*dutyCycle)) { 
        LedOn=LOW;
        lastSMART=millis();
        digitalWrite(LED_SMART, LOW);
    }    
  }else{
    if ((millis() - lastSMART) > round(DELAY_SMART*(1-dutyCycle))) { 
        LedOn=HIGH;
        lastSMART=millis();
        digitalWrite(LED_SMART, HIGH);
    }  
  }
}