void lcd_init();
void lcd_command(char cmd)  ; //send commends to LCD
void lcd_out(unsigned char value)  ;  // send data to LCD as (char)
void lcd_print(char *str) ; // print string
void lcd_go_to(unsigned char x,unsigned char y) ;  // determine position
void lcd_int(int value)  ; // print integer value 
