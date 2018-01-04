#include<avrio.h>
#define F_CPU 16000000
#define BAUD 9600

#include<avrio.h>
#include<util/baud.h>
#include<util/delay.h>

void main()
{
  int a=23;
  char b[3]={'h','a','i'};
  Serial_begin();
  Serial_write(b);
  _delay_ms(1000);
  Serial_print(a);
}
/****************************************************************************Serial_print-for sending numbers through UART*/
void Serial_print(unsigned int value)
{
	int x,y,i;
	unsigned char c[10];
	y=value;
	for(i=0;y>0;i++)                                                            //converting integers to characters
	{
		x=y%10;
		c[i]=x+'0';
		y=y/10;
	}
	
	i--;
	for(;i>=0;i--)
	{
		write(c[i]);
		_delay_ms(10);
	}
}
/****************************************************************************Serial_begin-for initializing UART*/
void Serial_begin(void)
{
	UBRR0H = UBRRH_VALUE;                                                      //assigning UBRRn
	UBRR0L = UBRRL_VALUE;
	UCSR0A = (USE_2X<<U2X0);                                                   //setting 2X speed
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);                            //setting receive interrupt enable & receive enable & transmit enable bits
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);                                        //
	
}
/****************************************************************************Serial_write-for sending strings*/
void Serial_write(unsigned char data[50])
{
	for(int i=0;data[i]!='/0';i++)
  {
    write(data[i]);
  }
}
/****************************************************************************write-for sending characters*/
void write(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));                                            //wait till buffer is free
	UDR0 = data;                                                              //copy data to buffer
}
