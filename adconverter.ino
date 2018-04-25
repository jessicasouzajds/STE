// --- SISTEMAS EMBARCADOS ---
// Aula dia 16/03/2018
// Aluna: Jessica de Souza 
// Atividade: https://wiki.sj.ifsc.edu.br/wiki/index.php/ESTE:_Analog-to-Digital_Converter_(ADC)_and_Sensor_Reading
// Implementação de um conversor analógico-digital
 
#include <SoftwareSerial.h>
 
int baud_rate = 9600;
int sensorValue;
float val;
float accumulated;
float average;

void setup() {
    Serial.begin(baud_rate); 
    val=0.0;
}

float Accumulate(int repeat){
   accumulated = 0.0;
   for(int i=0; i <= repeat; i++){
     sensorValue = (int) analogRead(A5);   //convert the analog-value (voltage) to digital one (0-1024)
     accumulated += sensorValue*sensorValue;      //accumulate all the digital-values “repeat” times
   }
   return accumulated;
}

float RMS(int repeat){
    accumulated = Accumulate(repeat);
    float average = accumulated / repeat;
    return sqrt(average);
}

void loop() {
  while(1){
    val = RMS(30);
    Serial.print("Digital: ");
    Serial.println(val);
    float voltage = val * (5.0 / 1023.0);
    Serial.print("Tensao: ");
    Serial.println(voltage);
    delay(1000);
  }
}
