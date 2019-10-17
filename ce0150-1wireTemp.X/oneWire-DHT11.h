#ifndef ONEWIRE_DHT11
#define ONEWIRE_DHT11

typedef union 
{
    struct 
    {
        unsigned char ;
        unsigned char temperatura;
        unsigned char ; 
        unsigned char umidade;
    };
    struct
    {
        unsigned long umidade_temperatura;
    };
} DHT;


void initDHT11( void );
unsigned char dht( DHT * ptr );



/****************** Como usar?
 * void main( void )
 * {
 *     DHT sensor;             // Declara��o da vari�vel com o tipo que receber� 
 *                             // os dados lidos pelo sensor de temperatura e 
 *                             // umidade.
 *  
 *     initDHT11();            // Inicializa��o/Habilita��o do pino ligado ao sensor
 *     
 *     
 *     if( dht( &sensor ) )    // Chamada da rotina com endere�o da vari�vel de 
 *                             // destino para os dados.
 *                             // Se o retorno for verdadeiro, os dados est�o �ntegros.
 *     {
 *         sensor.temperatura; // Valor da temperatura [�C].
 *         sensor.umidade;     // Valor da umidade [%].
 *     }
 * }
 */

#endif
