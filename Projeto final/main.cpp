//OBS: Nao esquecer de remover a configuracao de io16.h: va em
//properties>c/c++ general>paths and symbols>symbols (deletar io16 e verificar se f_cpu esta correta)
//Insert in avrdude: -c arduino, atmel AVR ISP mkll
//fazer primeiro com buffer e depois com a fifo

#include <avr/interrupt.h>
#include "UART.h"
#include "Singleton.h"
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>

#define F_CPU 16000000UL

unsigned char fifoRx;
unsigned char fifoTx;
bool has_data;


/*  RXINTERRUPT:
	bufferRx<=UDR0
	trata interrupcao
	hasdata = true
fim */
void rx_interrupt(){
	fifoRx = UDR0;
	has_data = true;
}

/*  TXINT
	//TEM_TX?
	se nao:DESABILITA
	se sim: udr0 = BUFFERtX
fim*/

void tx_interrupt(){
	if(has_data){
		UDR0 = fifoTx;
	}else{
		has_data = false;
	}

}

int main(){

	unsigned char a;
	int aux;
	//unsigned long br,DataBits_t db,ParityBits_t pr,StopBits_t sb,DoubleSpeed_t ds
	UART teste(9600,UART::bits8,UART::disabled,UART::um_bit,UART::off);

	sei(); // enable interrupts

	//loop
	while(true){
		aux = teste.getFifoSize();

		if(aux > 5){
			while(teste.has_data()){
					a = teste.get();
					teste.put(a);
			}

		}
	}//end loop

	return 0;
}
