// --- SISTEMAS EMBARCADOS ---
// Aula dia 26/03/2018
// Aluna: Jessica de Souza
// Atividade:  https://wiki.sj.ifsc.edu.br/wiki/index.php/ESTE:_GPIO_and_External_Interrupts_-_part_1
// DESCRICAO: This is an experiment with an led and a push button, using the GPIO to consolidate concepts of interrupts

#include <SoftwareSerial.h>

volatile boolean led_state = 1;  //state = 0, led is off; state = 1, led is on
int debounce_limit = 300;        //limit time in ms between interrupts to debounce the electric signal

const int button1 = 2;           //The button is an external interrupt
const int led1 =  8; 

unsigned long now;
unsigned long before;

void setup() { 
  pinMode(led1, OUTPUT);     //Inicializes the LED as an output
  pinMode(button1, INPUT);   //Inicializes the BUTTON as an input
  before = millis();         //Starts counting the time right before the interruption
  attachInterrupt(digitalPinToInterrupt(button1), interrupt_handler, RISING); //start the interruption
}

void loop() {
   digitalWrite(led1, led_state); //Changes the LED state  as its variable
}

void interrupt_handler(){
    now = millis(); //Starts counting the time right after the interruption is launched
    if( (now - before) > debounce_limit) {
        before = now;
        led_state = !led_state; //changes the LED state according to the debounce limit
    }
}