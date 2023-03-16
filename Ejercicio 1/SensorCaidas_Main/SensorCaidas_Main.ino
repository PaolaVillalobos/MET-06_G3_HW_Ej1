#include <OneWire.h>                
#include <DallasTemperature.h>

void setup() {
  TemperaturaSetup();
  // BotonPanicoSetup();
}
 
void loop() {
  TemperaturaLoop();  
  // BotonPanicoLoop(); 
}