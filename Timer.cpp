

#include "Define.h"

void Timer2Config()
{  
	cli(); // Disable global interrupt to protect critic area
    
    bitClear (TCCR2A, WGM20); // WGM20 = 0
    bitClear (TCCR2A, WGM21); // WGM21 = 0
    TCCR2B = 0b00000110; // Clock / 256, so 16 micro-s and WGM22 = 0
    TIMSK2 = 0b00000001; // local interruption allow by TOIE2
    
	sei(); // activate global interruption
}


