#ifndef UART_H_
#define UART_H_

#include "FIFO.h"
#include "Singleton.h"

class UART : public Singleton<UART> {
public:
	//bit 3 - USBS0
	enum StopBits_t {
		um_bit = 0,
		dois_bits = 8 };

	//bit 4,5 - UPM0[1,0]
	enum ParityBits_t {
		disabled = 0,
		enable_even = 32,
		enable_odd = 48	};

	//bit 1,2 - UCSZ0[1,0]
	enum DataBits_t {
		bits5 = 0,
		bits6 = 2,
		bits7 = 4,
		bits8 = 6 };
	
	//bit 1 - u2x0
	enum DoubleSpeed_t {
		off = 0,   //divider = 16
		on = 2};   //divider = 8 (2x transfer rate)

	UART(unsigned long br,DataBits_t db,ParityBits_t pr,StopBits_t sb,DoubleSpeed_t ds);
	bool has_data();
	void put(unsigned char data);    //write - tx
	unsigned char get();			 //read - rx
	int getFifoSize();
	static void handler_rx();
	static void handler_tx();

private:
	unsigned long _baudrate;
	DataBits_t _databits;
	ParityBits_t _parity;
	StopBits_t _stopbits;
	DoubleSpeed_t _ds;

	bool b_rx_data;

	//typedef
	FIFO<char, 8> tx;
	FIFO<char, 8> rx;

};

#endif /* UART_H_ */
