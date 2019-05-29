#include <LPC21xx.H>
#include "timer.h"

#define CounterEnable (1<<0)
#define CounterReset (1<<1)
#define Register0Interrupt (1<<0)
#define InterruptFlagReset (1<<0)
#define MatchRegisterReset (1<<1)
#define PresqualerValue 15

void InitTimer0(){
	
	T0TCR = (T0TCR | CounterEnable);
}	

void WaitOnTimer0(unsigned int uiTime){
	T0TCR = (T0TCR | CounterReset);
	T0TCR = (T0TCR & (~CounterReset));
	while(T0TC<uiTime*PresqualerValue){		
	}
}

void InitTimer0Match0(unsigned int iDelayTime){ 
	T0MR0 = (PresqualerValue*iDelayTime);
	T0MCR = (T0MCR | Register0Interrupt | MatchRegisterReset);
	T0TCR = (T0TCR | CounterReset);
	T0TCR = T0TCR & (~CounterReset);
	T0TCR = T0TCR | CounterEnable;
}
void WaitOnTimer0Match0(){
	while((T0IR & InterruptFlagReset) == 0) {
	}
	T0IR = InterruptFlagReset;
}
