/*
 * GccApplication13.c
 *
 * Created: 9/8/2020 12:21:32 AM
 * Author : MUSTAFA
 */ 

#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <file.h>
//#include <LCD-driver filhe.c>
 main()
{
		DDRD|=(1<<0)|(1<<3)|(1<<7);
		lcd_init();
		while (1)
		{
			for(int k=9;k>=0;k--)   //FIRST LOOP (STOP)
			{
							if(k==9)
							{
									 lcd_go_to(1,8);
									lcd_command(0xC);
									lcd_print("STOP");
									_delay_ms(100);
									lcd_command(0x1);
							}
									 lcd_go_to(1,1);
									  lcd_print("Remaining");
									  lcd_go_to(1,12);
									  lcd_int(k);
									  lcd_go_to(1,14);
									  lcd_print("sec");
									  PORTD&=~(1<<7);
									  PORTD|=(1<<0);
									  lcd_command(0xC);
									  if(k==0)
									  {
										   lcd_command(0x1);
									  }
			}
				  for(int k=4;k>=0;k--)  //SECOND LOOP (READY)
				  {
								  if(k==4)
								  {
									  lcd_go_to(1,8);
									  lcd_command(0xC);
									  lcd_print("READY");
									  _delay_ms(100);
									  PORTD&=~(1<<0);
									  PORTD|=(1<<3);
									  lcd_command(0x1);
								  }
								  lcd_go_to(1,1);
								  lcd_print("Remaining");
								  lcd_go_to(1,12);
								  lcd_int(k);
								  lcd_go_to(1,14);
								  lcd_print("sec");
								  PORTD&=~(1<<0);
								  PORTD|=(1<<3);
								  lcd_command(0xC);
								  if(k==0)
								  {
									  lcd_command(0x1);
								  }
				  }
				  for(int k=9;k>=0;k--) //the third (GO)
				  {
								  if(k==9)
								  {
									  lcd_go_to(1,8);
									  lcd_command(0xC);
									  lcd_print("GO");
									  _delay_ms(100);
									  PORTD&=~(1<<0);
									  PORTD&=~(1<<3);
									  PORTD|=(1<<7);
									  lcd_command(0x1);
								  }
								  lcd_go_to(1,1);
								  lcd_print("Remaining");
								  lcd_go_to(1,12);
								  lcd_int(k);
								  lcd_go_to(1,14);
								  lcd_print("sec");
								  lcd_command(0xC);
								  if(k==0)
								  {
									  lcd_command(0x1);
								  }
						}

	}

	return 0;
	
}
