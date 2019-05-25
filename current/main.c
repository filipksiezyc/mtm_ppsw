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

	enum LedState{STAY,BLINK, STEP_RIGHT};
	enum LedState eLedState = STAY;
	unsigned char ucBlinkCounter;

	KeyboardInit();
	LedInit();


	while(1){
		switch(eLedState){
			case STAY:
				LedOn(0);
				if (eKeyboardRead()== BUTTON_2){
					eLedState=BLINK;
				}
				else if(eKeyboardRead()==BUTTON_1){
					eLedState=STEP_RIGHT;
				}
					break;
			case BLINK:
				if(eKeyboardRead() == BUTTON_0){
					eLedState=STAY;
				}
				else{
					if(ucBlinkCounter==1){
						LedOn(0);
						ucBlinkCounter=0;
					}
					else if(ucBlinkCounter==0){
						LedOn(4);
						ucBlinkCounter=1;
					}
				}
				break;
			case STEP_RIGHT:
				if(eKeyboardRead() == BUTTON_0){
					eLedState=STAY;
				}
				else{
					LedStepRight();
				}
		}
		Delay(100);
}
