/*******************************************************
Project : 
Version : 
Date    : 12/11/2015
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/
#include <mega16.h>
#include <alcd.h>
#include <delay.h>
char A[4][4]={{'7','8','9','?'},{'4','5','6','X'},{'1','2','3','-'},{'O','0','=','+'}};
void getCols_print(char x){
    DDRD=1<<x;
    PORTD=0b11110000;
    if(!PIND.4) lcd_putchar(A[x][0]);
    if(!PIND.5) lcd_putchar(A[x][1]);
    if(!PIND.6) lcd_putchar(A[x][2]);
    if(!PIND.7) lcd_putchar(A[x][3]);
}

void main(void)
{
lcd_init(16);
DDRD  = 0b00001111;
PORTD = 0b11110000;

while (1){
    //delay_ms(100);
    if(PIND != 0b11110000){
        DDRD=0b00000001;
        if(PIND!= 0b11110000){getCols_print(0);}
        DDRD=0b00000010;
        if(PIND!= 0b11110000){getCols_print(1);}
        DDRD=0b00000100;
        if(PIND!= 0b11110000){getCols_print(2);}
        DDRD=0b00001000;
        if(PIND!= 0b11110000){getCols_print(3);}
        DDRD  = 0b00001111;
        PORTD = 0b11110000;      
        while(PIND != 0b11110000);
 
    }
      
      
}
}
