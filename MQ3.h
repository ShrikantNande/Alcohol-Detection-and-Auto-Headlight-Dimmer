
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
unsigned char *String1 = "alcohol detected";
unsigned char *String2 = " DRIVE SAFE";

unsigned int i, j;
void delay()
{
 for(i = 0; i < 100; i++)
         for(j=0;j<500;j++);
}



int mq3()
{
  unsigned char key =0;
     InitLCD();
    if(PORTDbits.RD3==1) key=1;
    if(PORTDbits.RD3==0)  key=0;
    
if(key==1)
{
        PORTDbits.RD5=0;
        PORTCbits.RC7=1;
        while(*String1)
 {
  SendData(*String1);
  *String1++;
 }
delay();
}
if(key==0)
    {
    PORTDbits.RD4=0;
    PORTCbits.RC7=0;
 SendInstruction(0xC0);      //set address to 2nd line
 while(*String2)
 {
  SendData(*String2);
  *String2++;
  }
 delay();
 }
   return 0;
}