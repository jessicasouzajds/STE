// --- SISTEMAS EMBARCADOS ---
// Aula dia 05/03/2018
// Aluna: Jessica de Souza 

//Atividade: https://wiki.sj.ifsc.edu.br/wiki/index.php/ESTE:_General_Purpose_Input_and_Output_(GPIO)
// Testando as GPIOs do Arduino

const int button1 = 2;   
const int button2 = 3;   

const int led1 =  8; 
const int led2 =  9; 
int buttonState1 = 0; 
int buttonState2 = 0; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(led1, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led1, LOW);
  }

    if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(led2, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led2, LOW);
  }
}
