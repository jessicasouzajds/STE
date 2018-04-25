/*
 * main.cpp
 *
 *  Created on: 9 de abr de 2018
 *      Author: Jessica de Souza
 */

//arquivo do arduino: includes>usr/lib/avr/include>avr > iom328p.h

#  include <stdio.h>
#  include <avr/io.h>

void setup(){
     DDRD &= ~(1 << 7);
     DDRD |= (1 << 0);

     PORTD &= ~(1 << 0);
}

void loop(){
    if(PIND & (1 << 7))
        PORTD |= (1 << 0);
    else
        PORTD &= ~(1 << 0);
}

int main(){
    setup();
    while(true)
        loop();
    return 1;
}