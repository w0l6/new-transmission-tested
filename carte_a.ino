int pinData = 4;  // (clock)
int pinSend = 3;  // envoyer l'octet

void setup() {
  pinMode(pinData, OUTPUT); 
  pinMode(pinSend, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  byte dataToSend = 128; 
  envoyer(dataToSend);    
  delay(1000);            
}


void envoyer(byte dataToSend) {
  Serial.print("Envoi de l'octet: ");
  Serial.println(dataToSend, DEC); 

 
  digitalWrite(pinData, HIGH); 
  delay(50);  
  digitalWrite(pinData, LOW);   

  
  for (int i = 7; i >= 0; i--) {
    bool bit = (dataToSend >> i) & 1;  
    Serial.print("Envoi du bit: ");
    Serial.println(bit); 

    if (bit) {
      digitalWrite(pinSend, HIGH);  
    } else {
      digitalWrite(pinSend, LOW);  
    }
    delay(100);  
  }
}

