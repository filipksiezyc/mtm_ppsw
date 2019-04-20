
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
	KeyboardInit();
	LedInit();
	while(1){
		switch (eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;	
			default: break;
	  }
		Delay(10);
	}
} 

				
						
			
		
	
	