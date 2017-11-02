#include <sensirion_ess.h>

SensirionESS ess;

int ledRed = 9;
int ledOrange = 10;
int ledGreen = 11;

void setLedStates(int ledRedValue, int ledOrangeValue, int ledGreenValue) {
  digitalWrite(ledRed, ledRedValue);
  digitalWrite(ledOrange, ledOrangeValue);
  digitalWrite(ledGreen, ledGreenValue);
}

void setup()
{
  Serial.begin(9600);
  delay(1000); // let console settle

  if (ess.initSensors() != 0) {
      Serial.print("Error while initializing sensors: ");
      Serial.print(ess.getError());
      Serial.print("\n");
      while (1) { // loop forever
        delay(1000);
      }
  }

  pinMode(ledRed, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  float temp, rh, tvoc = -1;

  if (ess.measureRHT() != 0) {
    Serial.print("Error while measuring RHT: ");
    Serial.print(ess.getError());
    Serial.print("\n");
  } else {
    temp = ess.getTemperature();
    rh = ess.getHumidity();
  }

  if (ess.measureIAQ() != 0) {
    Serial.print("Error while measuring IAQ: ");
    Serial.print(ess.getError());
    Serial.print("\n");
  } else {
    tvoc = ess.getTVOC();

    if (tvoc > 70) {
      setLedStates(1, 0, 0);
    } else if (tvoc > 55) {
      setLedStates(0, 1, 0);
    } else {
      setLedStates(0, 0, 1);
    }
  }

  Serial.print(temp);
  Serial.print(" ");
  Serial.print(rh);
  Serial.print(" ");
  Serial.print(tvoc);
  Serial.print(" ");
  Serial.print("\n");

  delay(ess.remainingWaitTimeMS());
}
