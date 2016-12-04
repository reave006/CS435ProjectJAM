#include "mbed.h"
#include "pindef.h"

Serial device(UART_TX, UART_RX);

PwmOut speaker(PB_10);//PWM speaker = PB_10

DigitalIn C(PA_10);
DigitalIn D(PB_3);
DigitalIn E(PB_5);

DigitalIn playBack(PA_8);

BusOut lights(PA_9,PC_7,PB_6);

const int MAXNOTES=50;
int notes=0;//count how many notes are played for recorder.
char noteArray[MAXNOTES];//hold all the notes

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main()
{
	device.baud(9600);

	C.mode(PullDown);
	D.mode(PullDown);
	E.mode(PullDown);
	playBack.mode(PullDown);
	
while(1)
{
	if(notes<MAXNOTES)
	{
		if(C == 1)
		{
			speaker.period(1/523.25);//C
			speaker=.5;//play note C5
			device.printf("C, ");
			noteArray[notes]='C';
			notes++;
		
			while(C==1)
			{
			}
		}
	
		if(D == 1)
		{
			speaker.period(1/587.33);//D
			speaker=.5;//play note D5
			device.printf( "D, ");
			noteArray[notes]='D';
			notes++;
		
			while(D==1)
			{
			}
		}
		if(E == 1)
		{
			speaker.period(1/659.26);//E
			speaker=.5;//play note E5
			device.printf("E, ");
		
			noteArray[notes]='E';
			notes++;
		
			while(E==1)
			{
			}
		}
	}
	else
	{
		speaker=0;
	}
		if(playBack == 1)
		{
		
				for (int i=0; i<notes; i++)
			{
					if(noteArray[i]=='C')
					{
						speaker.period(1/523.25);//C
						lights=1;
					}
					if(noteArray[i]=='D')
					{
						speaker.period(1/587.33);//D
						lights=2;
					}
					if(noteArray[i]=='E')
					{
						speaker.period(1/659.26);//E
						lights=4;
					}
					
					speaker=.5;
					wait(.5);
					lights=0;
			}
			speaker=0;
			notes=0;
			
			
	}
	wait(.1);
	speaker = 0;
	
 }
}
