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
	
	enum LedState{STEP_RIGHT,STAY};
	enum LedState eLedState=STEP_RIGHT;
	
	KeyboardInit();
	LedInit();


	while(1)
	{
		switch(eLedState){
			case STEP_RIGHT:
				LedStepRight();
				if(eKeyboardRead()==BUTTON_0){
					eLedState=STAY;
				}
				break;
			case STAY:
				if(eKeyboardRead()==BUTTON_1){
					eLedState=STEP_RIGHT;
				}
				break;
		}
		Delay(100);
}
}
