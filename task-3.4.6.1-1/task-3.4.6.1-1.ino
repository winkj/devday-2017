void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int counter = 1; 
void loop() { 
  Serial.println(counter); 
  delay(250); 
  counter = counter + 1; 
  if (counter > 10) { 
    counter = 1; 
  } 
}
