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


#endif
