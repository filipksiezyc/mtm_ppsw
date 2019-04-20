#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

void LedInit() {
	IO1SET=LED0_bm;
	IO1DIR = IO1DIR|LED0_bm|LED1_bm|LED2_bm|LED3_bm; 
}
enum eStep {RIGHT, LEFT};

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