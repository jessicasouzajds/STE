// --- SISTEMAS EMBARCADOS ---
// Aula dia 16/03/2018
// Aluna: Jessica de Souza 

// Atividade: https://wiki.sj.ifsc.edu.br/wiki/index.php/ESTE:_Universal_Assynchronous_Receiver_and_Transmitter_(UART)
// Implementação de porta serial, incrementador de byte

#include <SoftwareSerial.h>
#define x 30;

byte byte_recived;
int baud_rate = 9600;

void setup() {
    Serial.begin(baud_rate); 
    Serial.println("oi");
}

void loop() {
  if (Serial.available()){
    byte_recived = Serial.read();
    ++ byte_recived;
    Serial.write(byte_recived);
  }
}
