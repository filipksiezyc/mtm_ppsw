#include "led.h"
#include "keyboard.h"

void Delay(int iHowLongDelay) 
{
	int iMiliSecond = 5997; 
	unsigned int uiCounter; 
	char cCharIncrementation;

	for(uiCounter=0; uiCounter < (iHowLongDelay*iMiliSecond); uiCounter++) {
		cCharIncrementation++; 
	}
}


int main(){

	enum LedState{STEP_RIGHT,STEP_LEFT, STAY};
	enum LedState eLedState = STAY;
	KeyboardInit();
	LedInit();


	while(1){
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
		Delay(100);
}
}
