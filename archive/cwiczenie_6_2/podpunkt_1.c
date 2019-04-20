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

	enum LedState{LED_LEFT,LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	LedInit();
	KeyboardInit();

	while(1)
	{
		switch(eLedState){
			case LED_LEFT:
				LedStepRight();
				eLedState = LED_RIGHT;
				break;
			case LED_RIGHT:
				LedStepLeft();
				eLedState = LED_LEFT;
				break;
		}
		Delay(100);
}
}
