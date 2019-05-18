
#include <xc.h>
#include<p18f4550.h>
#include "config4550.h"
#include "setup.h"
#include "lcd.h"
#include "ADC.h"
#include "MQ3.h"

void main(void) {
    con();
    while(1)
    {
    LDR_Result();
    mq3();
    }
  }
