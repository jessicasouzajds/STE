/*
 * UART.cpp
 *
 *  Created on: 16 de ago de 2018
 *      Author: aluno
 */
#include "UART.h"
#include <avr/interrupt.h>
#include <avr/io.h>

UART::UART(unsigned long br,DataBits_t db,ParityBits_t pr,StopBits_t sb,DoubleSpeed_t ds):_baudrate(br),_databits(db),_parity(pr),_stopbits(sb), _ds(ds)
{
	//Register A, setting the double speed
	UCSR0A |= ds;  //U2X0

	//UPM01 e 0, USBS0, UCSZ01,
	UCSR0C = db | pr | sb;

	//UBRRn
	if(ds==0){
		UBRR0 = (F_CPU/(16ul*br))-1; //unsigned long = ul
	}else{
		UBRR0 = (F_CPU/(8ul*br))-1;
	}

	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);
	b_rx_data =false;

}

bool UART::has_data(){
	//verifica se tamanho fifo é zero
	return b_rx_data;
}

void UART::put(unsigned char data){   //write,tx
	tx.push(data);
	UCSR0B |= (1 << UDRIE0);
}

int UART::getFifoSize(){
	return rx.get_size();
}

unsigned char UART::get(){	//read,rx
	b_rx_data = false;
	return self()->rx.pop();
}


ISR(USART_RX_vect){
	UART::handler_rx();
}

void UART::handler_rx(){
	self()->rx.push(UDR0); //le o que ta na fifo no registrador de dados
	self()->b_rx_data = true;
}

ISR(USART_UDRE_vect){
	UART::handler_tx();
}

void UART::handler_tx(){
	UDR0 = self()->tx.pop();  //escreve o que ta na fifo no registrador de dados
	UCSR0B &= ~(1 << UDRIE0);
}
