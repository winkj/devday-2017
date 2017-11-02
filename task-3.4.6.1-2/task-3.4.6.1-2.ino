int ledRed = 9; 
int ledOrange = 10; 
int ledGreen = 11; 

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
    digitalWrite(ledRed, HIGH); 
    digitalWrite(ledOrange, LOW); 
    digitalWrite(ledGreen, LOW); 
  } else if (counter >=4) { 
    digitalWrite(ledRed, LOW); 
    digitalWrite(ledOrange, HIGH); 
    digitalWrite(ledGreen, LOW); 
  } else { // counter < 4 
    digitalWrite(ledRed, LOW); 
    digitalWrite(ledOrange, LOW); 
    digitalWrite(ledGreen, HIGH); 
  } 
  delay(250); 
  counter = counter + 1; 
  if (counter > 10) { 
       counter = 1; 
  } 
}
