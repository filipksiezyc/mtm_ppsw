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

	enum LedState{BUTTON_PUSHED0, DEFAULT_STAY};
	enum LedState eLedState = DEFAULT_STAY;
	KeyboardInit();
	LedInit();
	char cStepBeforeStateChange = 0;

	while(1)
	{
		switch(eLedState){
			case DEFAULT_STAY:
				if(eKeyboardRead()==BUTTON_0){
					eLedState=BUTTON_PUSHED0;
					break;
				}
			case BUTTON_PUSHED0:
				LedStepRight();
				cStepBeforeStateChange++;
				if(cStepBeforeStateChange==3){
				eLedState=DEFAULT_STAY;
				break;
				}
		}
		Delay(100);
}
}
