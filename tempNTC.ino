// --- SISTEMAS EMBARCADOS ---
// Aula dia 16/03/2018
// Aluna: Jessica de Souza 
// Atividade: https://wiki.sj.ifsc.edu.br/wiki/index.php/ESTE:_Analog_Temperature_Sensor_2_(NTC_-_Negative_Temperature_Coeficient)
// Sensor de temperatura analógico NTC
 
#include <SoftwareSerial.h>
 
int baud_rate = 9600;
float accumulated;
float sensorValue;
float v0;
float res1;
float res;
float temp;
float TK;
float TC;

#define T0 298.15
#define R0 10000.0
#define betah 3950.0
#define vin 5.0

float Accumulate(int repeat){
   accumulated = 0;
   for(int i=0; i <= repeat; i++){
      sensorValue = (int) analogRead(A5);          //convert the analog-value (voltage) to digital one (0-1024)
      accumulated += sensorValue*sensorValue;      //accumulate all the digital-values “repeat” times
   }
   return accumulated;
}

float Temperature(float val){
    v0 = val*vin;
    v0 = v0/1024; 
    res1 = R0*vin;
    res = res1/v0;
    res = res - R0;

    delay(1000);
    TK =  1/T0 +((1/betah)*log(res/R0));
    TK = 1/TK;
    TC = (TK - 273.15);
    return TC;
}

float RMS(int repeat){
    accumulated = Accumulate(repeat);
    float average = accumulated / repeat;
    return sqrt(average);
}

void setup() {
    Serial.begin(baud_rate); 
}

void loop() {
  while(1){
    float val = RMS(30);
    float temp = Temperature(val);
    Serial.println(temp);
  }
}
