int ledRed = 9; 
int ledOrange = 10; 
int ledGreen = 11; 

void setLedStates(int redValue, int orangeValue, int greenValue) { 
  digitalWrite(ledRed, redValue); 
  digitalWrite(ledOrange, orangeValue); 
  digitalWrite(ledGreen, greenValue);
}

void setup() { 
  Serial.begin(9600); 
  pinMode(ledRed, OUTPUT); 
  pinMode(ledOrange, OUTPUT); 
  pinMode(ledGreen, OUTPUT); 
} 

int counter = 1; 
void loop() { 
  Serial.println(counter); 
  if (counter >= 7) { 
    setLedStates(HIGH, LOW, LOW); 
  } else if (counter >=4) { 
    setLedStates(LOW, HIGH, LOW);
  } else { // counter < 4 
    setLedStates(LOW, LOW, HIGH);
  }
  delay(250); 
  counter = counter + 1; 
  if (counter > 10) { 
       counter = 1; 
  } 
}
