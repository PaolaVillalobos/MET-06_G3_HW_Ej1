#include <OneWire.h>                
#include <DallasTemperature.h>

void setup() {

  Serial.begin(9600);
  BotonPanico_Setup();
  TempHum_Setup();
  Presencia_Setup();
}
 
void loop() {
  BotonPanico_Loop(); 
  TempHum_Loop();   
  Presencia_Loop();
  
}