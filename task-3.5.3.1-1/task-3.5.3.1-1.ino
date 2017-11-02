void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int counter = 1; 
int tenCounter = 1; 
void loop() { 
  Serial.print(tenCounter); 
  Serial.print(" "); 
  Serial.println(counter); 
  delay(250); 
  counter = counter + 1; 
  if (counter > 10) { 
    counter = 1; 
    tenCounter = tenCounter + 1; 
  } 
}
