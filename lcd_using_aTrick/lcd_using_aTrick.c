/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/27/2015
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
#include <delay.h>


// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here


flash char A[4][4]={{'7','8','9','/'},
              {'4','5','6','X'},
              {'1','2','3','-'},
              {'O','0','=','+'}};   
              

// External Interrupt 2 service routine

interrupt [EXT_INT2] void ext_int2_isr(void)
{
char  columnNumber;
char rowNumber;
char position;
        if(PIND.4==0){
        columnNumber=0;
        } 
        if(PIND.5==0){
        columnNumber=1;
        }
        if(PIND.6==0){
        columnNumber=2;
        }
        if(PIND.7==0){
        columnNumber=3;
        }  
      
         DDRD.0=0  ;
         DDRD.1=0  ;
         DDRD.2=0 ;
         DDRD.3=0  ;
         PORTD.0=1 ;
         PORTD.1=1;
         PORTD.2=1 ;
         PORTD.3=1;
         DDRD.4=1  ;
         DDRD.5=1  ;
         DDRD.6=1 ;
         DDRD.7=1  ;
         PORTD.4=0  ;
         PORTD.5=0  ;
         PORTD.6=0   ;
         PORTD.7=0   ;
         
         if(PIND.3==0){
         rowNumber=3;
         }
         if(PIND.2==0){
         rowNumber=2;
         }
         if(PIND.1==0){
         rowNumber=1;
         }
         if(PIND.0==0){
         rowNumber=0;
         } 
             
             lcd_putchar(A[rowNumber][columnNumber]); 
             DDRD.7=0;  
             DDRD.6=0;
             DDRD.5=0;
             DDRD.4=0;
             DDRD.3=1;
             DDRD.2=1;
             DDRD.1=1;
             DDRD.0=1;
             PORTD.7=1;
             PORTD.6=1;
             PORTD.5=1;
             PORTD.4=1;
             PORTD.3=0;
             PORTD.2=0;
             PORTD.1=0;
             PORTD.0=0;

}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P 
PORTD=(1<<PORTD7) | (1<<PORTD6) | (1<<PORTD5) | (1<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: On
// INT2 Mode: Falling Edge
GICR|=(0<<INT1) | (0<<INT0) | (1<<INT2);
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(0<<INTF1) | (0<<INTF0) | (1<<INTF2);

lcd_init(16);


#asm("sei")

while (1)
      {
        //code
      }  
      
      
}

