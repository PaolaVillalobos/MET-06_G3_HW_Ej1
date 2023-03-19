#include <OneWire.h>                
#include <DallasTemperature.h>

void setup() {

  Serial.begin(9600);
  TempHum_Setup();
  // BotonPanicoSetup();
}
 
void loop() {
  TempHum_Loop();  
  // BotonPanicoLoop(); 
}