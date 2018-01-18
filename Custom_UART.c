#define F_CPU 16000000
#define BAUD 9600

#include <avr/io.h>
#include <util/setbaud.h>

int main(void)
{
	Serial_begin();
	unsigned int i=105;
	float j=12.054;
	char a='Q';
	Serial_int(i);
	Serial_write(0x0A);
	Serial_float(j);
	Serial_write(0x0A);
	Serial_write(a);
}
/***********************************************************************************************************Custom USART*/
void Serial_begin(void)
{
	UBRR0H = UBRRH_VALUE;                                                      //assigning UBRRn
	UBRR0L = UBRRL_VALUE;
	UCSR0A = (USE_2X<<U2X0);                                                   //setting 2X speed
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);                            //setting receive interrupt enable & receive enable & transmit enable bits
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);                                        //
	
}
/***********************************************************************************************************write*/
void Serial_write(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));                                            //wait till buffer is free
	UDR0 = data;                                                              //copy data to buffer
}
/***********************************************************************************************************Serial_int*/
void Serial_int(unsigned int f_data)
{
	int x,y,i;
	unsigned char c[10];
	y=f_data;
	if(y==0)
	{
		Serial_write(0x30);
	}
	else
	{
		for(i=0;y>0;i++)
		{
			x=y%10;
			y=y/10;
			c[i]=x+'0';
		}
		
		i--;
		for(;i>=0;i--)
		{
			Serial_write(c[i]);
			_delay_ms(10);
		}
	}
}

/***********************************************************************************************************Serial_float*/
void Serial_float(float f_data)
{
	unsigned char f_buf;
	unsigned int temp;
	temp=(int)f_data;
	Serial_int(temp);
	f_data=(f_data-temp);
	if(f_data>0)
	{
		Serial_write('.');
		for(int i=0;i<4;i++)
		{
			f_data=f_data*10;
			temp=(int)f_data;
			temp=(temp%10);
			if(temp==0)
			{
				Serial_write(0x30);
			}
			else
			{
				f_buf=temp+'0';
				Serial_write(f_buf);
			}
		}
	}
}