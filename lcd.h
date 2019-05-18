 
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    
    

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */
#include <p18f4550.h>
#include<stdio.h>

#define LCD_EN LATDbits.LD7
#define LCD_RS LATDbits.LD6
#define LCDPORT LATB


 unsigned int i , j ;

void strobe()
{
 LCD_EN = 1;		// EN High
     for(i = 0; i < 5; i++)
    {
            for(j=0;j<100;j++);
    }
 LCD_EN = 0;		// EN Low; command sampled at EN falling edge

}

void SendInstruction(unsigned char command)
{
     LCD_RS = 0;		// RS low : Instruction
     LCDPORT = command;
     strobe();    
}
void SendData(unsigned char lcddata)
{
     LCD_RS = 1;		// RS HIGH : DATA
     LCDPORT = lcddata;
     strobe();
}
void InitLCD(void)
{
    SendInstruction(0x38);      //8 bit mode, 2 line,5x7 dots
    SendInstruction(0x06);      // entry mode
    SendInstruction(0x0C);      //Display ON cursor OFF
    SendInstruction(0x01);      //Clear display
    SendInstruction(0x80);      //set address to 0
}



