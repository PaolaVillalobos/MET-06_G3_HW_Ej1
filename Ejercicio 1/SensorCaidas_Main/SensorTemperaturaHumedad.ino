#include "DHT.h" 

#define DHTPIN 10    //Pin where is the sensor connecte

#define DHTTYPE DHT22   // Sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

int maxTemp = 27;
bool triggerTemp = false;

const int CincoS = 5000;
int maxHum = 80;
bool triggerHum = false;
unsigned long lastCincoS = 0;

void TempHum_Setup(){
  Serial.println("Loading...");
  dht.begin(); 
  Led_Setup();
}

void TempHum_Loop(){
  
  
  if ((millis() - lastCincoS) >= CincoS) { 
    lastCincoS = millis();
  float h = dht.readHumidity(); //Reading the humidity 
  float t = dht.readTemperature(); //Reading the temperature in Celsius degree 

//--------Sending the reading through Serial port------------- 
  if (t > maxTemp){
    triggerTemp = true;
    Serial.println("EMERGENCIA TEMPERATURA!!!!");

    Led_Loop();
  }
  if (h > maxHum){
    triggerHum = true;
    Serial.println("EMERGENCIA HUMEDAD!!!!");

    Led_Loop();
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%; ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" ºC ");
  }
  

}
