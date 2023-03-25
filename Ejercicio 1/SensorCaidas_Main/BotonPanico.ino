
const int BUTTON_PIN = 13;
const int LED_GREEN = 15;

const int DEBOUNCE_DELAY = 50;
bool buttonState = HIGH;

bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;

void BotonPanico_Setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_GREEN, OUTPUT);
}

void BotonPanico_Loop() {

  bool reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) { 
    if (reading != buttonState) { // Hace que al estar presionado el boton solo salga EMERGENCIA una vez
      buttonState = reading;

      if (buttonState == HIGH) {
        Serial.println("Emergencia activada!");
        digitalWrite(LED_GREEN, HIGH); // Enciende el LED
      } else {
        digitalWrite(LED_GREEN, LOW); // Apaga el LED
      }
    }
  }

  lastButtonState = reading;

}
