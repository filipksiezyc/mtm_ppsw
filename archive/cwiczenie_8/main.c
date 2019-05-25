#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"

void Automat(){
	enum LedState{STEP_RIGHT,STEP_LEFT, STAY};
	enum LedState eLedState = STAY;
	
	KeyboardInit();
	LedInit();
	switch(eLedState){
			case STAY:
				if (eKeyboardRead()== BUTTON_0){
					eLedState=STEP_LEFT;
				}
				else if(eKeyboardRead() == BUTTON_2){
					eLedState=STEP_RIGHT;
				}
				break;
			case STEP_LEFT:
					if(eKeyboardRead()==BUTTON_1){
						eLedState=STAY;
					}
					else{
							LedStepLeft();
					}
					break;
		case STEP_RIGHT:
					if(eKeyboardRead()==BUTTON_1){
						eLedState=STAY;
					}
					else{
							LedStepRight();
					}
					break;
		}
}	

int main (){
	unsigned int iMainLoopCtr;	
	
	LedInit();
	KeyboardInit();
	Timer0Interrupts_Init(20000, &Automat);
	while(1){
	 	iMainLoopCtr++;

	}
}
