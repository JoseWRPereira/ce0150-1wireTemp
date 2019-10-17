/*
 * File:   main.c
 * Author: curtaeletronica
 *
 * Created on 14 de Outubro de 2019, 13:36
 * 
 * IDE:         MPLAB X IDE v3.15
 * Compiler:    XC8 v1.45
 * OS:          Deepin 15.11 X86_64
 * Kernel:      4.15.0-30deepin-generic
 * 
 * Objetivo: 
 *      Produzir comunicação serial via módulo Bluetooth HC-05.
 * 
 * Pinos    |nº     |Conexão
 *  VDD     |11,32  | Alimentação (Vcc/+5V)
 *  VSS     |12,31  | Alimentação (GND/0V)
 *  RD0     |19     | LCD_D4
 *  RD1     |20     | LCD_D5
 *  RD2     |21     | LCD_D6
 *  RD3     |22     | LCD_D7
 *  RC4     |23     | 1-Wire
 *  *RC6    |25     | TX
 *  *RC7    |26     | RX
 *  RD4     |27     | LCD_RS
 *  RD5     |28     | LCD_EN
 *  RD6     |29     | LCD_B0 (Botão 0)
 *  RD7     |30     | LCD_B1 (Botão 1)
 *  RB0     |33     | L1 : 123A
 *  RB1     |34     | L2 : 456B
 *  RB2     |35     | L3 : 789C
 *  RB3     |36     | L4 : *0#D
 *  RB4     |37     | C1 : 147*
 *  RB5     |38     | C2 : 2580
 *  RB6     |39     | C3 : 369#
 *  RB7     |40     | C4 : ABCD
 * 
*/

//***************** Bibliotecas
#include <xc.h>
#include "config.h"
#include "lcd4bitBus.h"
#include "keyboard.h"
#include "oneWire-DHT11.h"


void interrupt geral( void )
{
    INTCONbits.GIE = 0;

    
    INTCONbits.GIE = 1;
}




//***************** Programa Principal
void main(void)
{
    DHT sensor;
    unsigned char ut[17] = "T=      U=      ";

    initLCD();
    initKeyboard();
    initDHT11();
    
    
    lcd(0,0, "CurtaEletronica");

    while( 1 )                      // Laço de repetição infinita.
    {
        keyboardScan();
        
        if( currentKey() && !previousKey() )
        {
        }


        if( dht( &sensor ) )    // CRC ok
        {
            intTOstr((unsigned int)sensor.temperatura,  &ut[ 2], 0 );
            intTOstr((unsigned int)sensor.umidade,      &ut[10], 0 );
        }

        lcd(0,1,ut );

        __delay_ms(2000);
    }
    return;
}
//***************** Fim do Programa Principal
