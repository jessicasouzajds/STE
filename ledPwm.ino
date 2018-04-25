// --- SISTEMAS EMBARCADOS ---
// Aula dia 02/04/2018
// Aluna: Jessica de Souza 
// Atividade: https://wiki.sj.ifsc.edu.br/wiki/index.php/ESTE:_Pulse_Width_Modulation_(PWM)

// Modulação por largura de pulso (PWM)
 
const int led1 =  6; 
byte dutycycle_register;
byte timer_clock_register;

void setup() {
  pinMode(led1, OUTPUT); // initialize the LED pin as an output
  analogWrite(led1, 0);
}

void loop() { 
  set_pwm_frequency(0x05);
  TCCR0B = (TCCR0B & 0b11111000) | timer_clock_register;
  set_duty_cycle(127);
  analogWrite(led1,dutycycle_register);
  delay(5000);
 
  //fazendo a variacao do pwm frequency e do duty cycle (testar separado cada um):
    
  //  set_pwm_frequency(0x02);
  //  TCCR0B = (TCCR0B & 0b11111000) | timer_clock_register;
  //  set_duty_cycle(64);
  //  analogWrite(led1,dutycycle_register);
  //  delay(5000);
  
  //  set_pwm_frequency(0x03);
  //  TCCR0B = (TCCR0B & 0b11111000) | timer_clock_register;
  //  set_duty_cycle(128);
  //  analogWrite(led1,dutycycle_register);
  //  delay(5000);
  
  //  set_pwm_frequency(0x04);
  //  TCCR0B = (TCCR0B & 0b11111000) | timer_clock_register;
  //  set_duty_cycle(255);
  //  analogWrite(led1,dutycycle_register);
  //  delay(5000);
  
  //  set_pwm_frequency(0x05);
  //  TCCR0B = (TCCR0B & 0b11111000) | timer_clock_register;
  //  set_duty_cycle(64);
  //  analogWrite(led1,dutycycle_register);
  //  delay(5000);
}   
 
void set_duty_cycle(byte val){
    dutycycle_register = val;
}
 
void set_pwm_frequency(byte divi){
    timer_clock_register = divi;
}
