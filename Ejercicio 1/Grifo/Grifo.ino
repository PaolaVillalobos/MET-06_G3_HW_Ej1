#include <OneWire.h>                
#include <DallasTemperature.h>

void setup() {

  Serial.begin(9600);
  Grifo_setup();
}
 
void loop() {   
  Grifo_loop();

}