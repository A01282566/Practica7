#include "device_config.h"

#include <math.h>

#define _XTAL_FREQ 1000000 // Se define a qué frecuencia de reloj va a trabajar el micro

#define DELAY_SWEEP 300 //Pulsos del oscilloscopio para que mande la información

 

enum port_dir{output, input}; //Se restringen los valores

enum port_DCAC{digital, analog};

enum led_state{led_OFF, led_ON};

enum button_state{pushed, no_pushed};

enum exponent{bbase=2, limit=8};

//+++++ ISRs +++++++

//ISR para prioridades altas

__interrupt(high_priority) void high_isr (void){

    Nop(); // Funición que incluye un ciclo de instrucción

}

//ISR para prioridades bajas

__interrupt(low_priority) void low_isr (void){

    Nop();// Funición que incluye un ciclo de instrucción

}

//+++++Declaracion de funciones+++++++

void portsInit(void);//

int count = 0;

//++++++++MAIN+++++++++

void main(void) {

    //CONFIGURACIONES+++++++++++++

    portsInit();//

    //CICLO INFINITO+++++++++++++

    LATB = 0;

    int f = 0x00;

    int i = 0x00;

    int d = 0x00;

    while(1){

        LATB = 0xE0; //1110

        if(PORTBbits.RB7 == pushed) {

         i = f<<4;

         f = 0x0D;

         d = i|f;

         LATD = d;

        }

         else if (PORTBbits.RB6 == pushed){

         i = f<<4;

         f = 0x0C;

         d = i|f;

         LATD = d;  

         }

         else if (PORTBbits.RB5 == pushed){

         i = f<<4;

         f = 0x0B;

         d = i|f;

         LATD = d;  

         }

         else if (PORTBbits.RB4 == pushed){

         i = f<<4;

         f = 0x0A;

         d = i|f;

         LATD = d;  

         }            

    }

}

void portsInit( void ){

ANSELD = digital;

TRISD = output;

ANSELB = digital;

TRISB = 0b00001111;

LATD = 0x00;

}