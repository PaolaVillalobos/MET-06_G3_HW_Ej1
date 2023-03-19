// OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
 
// DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor
// int maxTemp = 27;
// bool triggerTemp = false;

// void TemperaturaSetup(){
//   delay(1000);
//   Serial.begin(9600);
//   sensors.begin();   //Se inicia el sensor
//   Led_Setup();
// }

// void TemperaturaLoop(){

//   sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
//   float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC

//   if (temp > maxTemp){
//     triggerTemp = true;
//     Serial.println("EMERGENCIA!!!!");

//     Led_Loop();
//   }

//   Serial.print("Temperatura= ");
//   Serial.print(temp);
//   Serial.println(" C");
//   delay(1000);   

// }