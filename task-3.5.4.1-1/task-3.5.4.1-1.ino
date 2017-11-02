#include <Wire.h>

#include "SHTSensor.h"

SHTSensor sht;
// To use a specific sensor instead of probing the bus use this command:
// SHTSensor sht(SHTSensor::SHT3X);

void setup() {
  // put your setup code here, to run once:

  Wire.begin();
  Serial.begin(9600);
  delay(1000); // let serial console settle

  if (sht.init()) {
      Serial.print("init(): success\n");
  } else {
      Serial.print("init(): failed\n");
  }
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // only supported by SHT3x

}

void loop() {
  // put your main code here, to run repeatedly:

  if (sht.readSample()) {

      float T = sht.getTemperature();
      float RH = sht.getHumidity();
      float H = (log10(RH)-2)/0.4343 + (17.62*T)/(243.12+T); 
      float Dp = 243.12*H/(17.62-H); // this is the dew point in Celsius
      
      Serial.print("SHT:\n");
      Serial.print("  RH: ");
      Serial.print(RH, 2);
      Serial.print("\n");
      Serial.print("  T:  ");
      Serial.print(T, 2);
      Serial.print("\n");
      Serial.print("  Dp:  ");
      Serial.print(Dp, 2);
      Serial.print("\n");
  } else {
      Serial.print("Error in readSample()\n");
  }

  delay(1000);
}
