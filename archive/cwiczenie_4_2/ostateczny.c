#include <LPC21xx.H>

#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

#define BUTTON0_bm 0x10
#define BUTTON1_bm 0x40
#define BUTTON2_bm 0x20
#define BUTTON3_bm 0x80

enum eKeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3}; 
enum eStep {RIGHT, LEFT};


void Delay(int iHowLongDelay) 
{
	int iMiliSecond = 5997; 
	unsigned int uiCounter; 
	char cCharIncrementation;
	
	for(uiCounter=0; uiCounter < (iHowLongDelay*iMiliSecond); uiCounter++) {
		cCharIncrementation++; 
	}
}
void LedInit() {
	IO1SET=LED0_bm;
	IO1DIR = IO1DIR|LED0_bm|LED1_bm|LED2_bm|LED3_bm; /* 0xF0000*/
	
}
void LedOn(unsigned char ucLedIndeks) {
		
	IO1CLR = LED0_bm|LED1_bm|LED2_bm|LED3_bm;	 
	switch(ucLedIndeks){
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
	}	 
																
}

void KeyboardInit()
{
		IO0DIR = IO0DIR & ~(BUTTON0_bm|BUTTON1_bm|BUTTON2_bm|BUTTON3_bm);
}


enum eKeyboardState eKeyboardRead(){
	
	if((IO0PIN&BUTTON0_bm) == 0 ){
		return BUTTON_0;
	}
	else if((IO0PIN&BUTTON2_bm) == 0 ){
		return BUTTON_1;
	}
	else if((IO0PIN&BUTTON1_bm) == 0 ){
		return BUTTON_2;
	}
	else if((IO0PIN&BUTTON3_bm)== 0){
		return BUTTON_3;
	}
	else{
	  return RELEASED;
}
}
 

void LedStep(enum eStep step){
	
	static unsigned int uiActualStep = 0;
	
	if(step == RIGHT){	
		uiActualStep++; 
	}
	else if(step == LEFT){
		uiActualStep--;
	}
	LedOn(uiActualStep % 4);
}

void LedStepRight(){
	LedStep(RIGHT);
}

void LedStepLeft(){
	LedStep(LEFT);
}


int main(){
	KeyboardInit();
	LedInit();
	while(1){
		switch (eKeyboardRead()){
			case 2:
				LedStep(RIGHT);
				break;
			case 3:
				LedStep(LEFT);
				break;	
			default: break;
	 }

		
		Delay(10);
	}
	
} 

				
						
			
		
	
	