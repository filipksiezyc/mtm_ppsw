#include <LPC21xx.H>
#include "timer.h"

#define CounterEnable (1<<0)
#define CounterReset (1<<1)
#define PresqualerHex 15

void InitTimer0(){
	
	T0TCR = (T0TCR | CounterEnable);
}	

void WaitOnTimer0(unsigned int uiTime){
	T0TCR = (T0TCR | CounterReset);
	T0TCR = (T0TCR & (~CounterReset));
	while(T0TC<uiTime*PresqualerHex){		
	}
}
	

