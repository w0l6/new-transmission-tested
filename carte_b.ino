int pinData = 4;  // clock
int pinReceive = 3;  // recevoir l'octet

byte receivedData = 0; 

void setup() {
  pinMode(pinData, INPUT);  
  pinMode(pinReceive, INPUT); 
  Serial.begin(9600); 
}

void loop() {
  receivedData = 0;  

 
  while (digitalRead(pinData) == LOW) {
    
  }


  delay(50); 

 
  for (int i = 7; i >= 0; i--) {
    bool bit = digitalRead(pinReceive);  
    Serial.print("Lecture du bit: ");
    Serial.println(bit);  

    if (bit) {
      receivedData |= (1 << i);  
    }
    delay(100);  
  }

  
  Serial.print("Octet reçu: ");
  Serial.println(receivedData, DEC);

  delay(1000);  
}

