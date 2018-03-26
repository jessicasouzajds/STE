// --- SISTEMAS EMBARCADOS ---
// Aula dia 23/03/2018
// Aluna: Jessica de Souza

//desafio: Usando Round Robin sem interrupções implementar um sistema com um LED e um botão.
//O sistema deve piscar o LED a cada 2 segundos e ao botão ser pressionado envia pela serial uma mensagem. 

#include <SoftwareSerial.h>

const int button1 = 2;   
const int led1 =  8; 

int buttonState1 = 0; 
int baud_rate = 9600;

void setup() {
  
  pinMode(led1, OUTPUT);   //Inicializa o LED como uma saida
  pinMode(button1, INPUT); //Inicializa o BOTAO como uma entrada
  Serial.begin(baud_rate); //Inicializa a serial com o b.r. desejado

}

//Da mais prioridade para a leitura de botao adicionando mais repeticoes
void loop() {

  digitalWrite(led1, HIGH);  //Acende o LED

  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
 
  digitalWrite(led1, LOW);  //Apaga o LED

  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();
  delay(250); readbtn();

}

void readbtn(){
 
  buttonState1 = digitalRead(button1); //Le o valor do botao

  //Se o botao esta pressionado, escreve na serial
  if (buttonState1 == LOW) {
     Serial.write("Serial\n ");
  } 
}