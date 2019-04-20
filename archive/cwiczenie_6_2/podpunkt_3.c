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

	enum LedState{LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	LedInit();
	char cStepBeforeStateChange;

	while(1)
	{
		switch(eLedState){
			case LED_LEFT:
				for(cStepBeforeStateChange=0; cStepBeforeStateChange<3 ; cStepBeforeStateChange++){
					LedStepLeft();
				}
				eLedState=LED_RIGHT;
				break;
			case LED_RIGHT:
				for(cStepBeforeStateChange=0; cStepBeforeStateChange<3 ; cStepBeforeStateChange++){
					LedStepRight();
				}
				eLedState=LED_LEFT;
				break;
		}
		Delay(100);
}
}
