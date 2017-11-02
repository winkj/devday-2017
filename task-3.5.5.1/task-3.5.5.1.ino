#include <Wire.h> 
#include "SHTSensor.h" 
SHTSensor sht; 

static const int ALERT_LED = 9; 
static const float RH_DIFFERENCE = 5; 
float rhRef = -1; // invalid value 

void setup() { 
  Wire.begin(); 
  Serial.begin(9600); 
  delay(1000); // let serial console settle 
  if (sht.init()) { 
    Serial.print("init(): success\n"); 
    if (sht.readSample()) { 
      rhRef = sht.getHumidity(); 
    } 
  } else { 
    Serial.print("init(): failed\n"); 
  } 
  pinMode(ALERT_LED, OUTPUT);
}

void loop() { 
  if (sht.readSample()) { 
    float delta = abs(rhRef - sht.getHumidity());
    if (delta > RH_DIFFERENCE) { 
      Serial.print("*"); 
      digitalWrite(ALERT_LED, HIGH); 
    } else { 
      Serial.print(" ");
      digitalWrite(ALERT_LED, LOW); 
    } Serial.print("RH delta: "); 
    Serial.print(delta, 2); 
    Serial.print("\n"); 
  } else { 
    Serial.print("Error in readSample()\n"); 
  } 
  delay(1000);
}
