#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

#define DETECTORSET_bm (1<<10)

enum DetectorState{ACTIVE, INACTIVE};
enum ServoState{CALLIB, IDLE, IN_PROGRESS};

struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};	

struct Servo sServo;

void DetectorInit(){
	IO0DIR= IO0DIR & (~DETECTORSET_bm);
}	

enum DetectorState eReadDetector(){
	
	if((IO0PIN & DETECTORSET_bm) == 0)
		return ACTIVE;
	else
		return INACTIVE;
	
}	


void Automat(){
	
	switch(sServo.eState){
			case CALLIB:
				sServo.uiCurrentPosition=0;
				sServo.uiDesiredPosition=0;
				if(eReadDetector() != ACTIVE){
					LedStepLeft();
				}
					else{
					sServo.eState=IDLE;
				}	
					
				break;
			case IDLE:
					if(sServo.uiCurrentPosition==sServo.uiDesiredPosition){
						sServo.eState=IDLE;
					}
					else{
						sServo.eState=IN_PROGRESS;
					}
					break;
		case IN_PROGRESS:
					if(sServo.uiCurrentPosition<sServo.uiDesiredPosition){
						LedStepLeft();
						sServo.uiCurrentPosition--;
					}
					else if(sServo.uiCurrentPosition>sServo.uiDesiredPosition){
						LedStepRight();
						sServo.uiCurrentPosition++;
					}
					else{
						sServo.eState=IDLE;
					}
					break;
		}
}	

int main(){
	enum eKeyboardState Stan;
	DetectorInit();
	while(1){
		
		switch(Stan){
			case BUTTON_0:
				sServo.eState=CALLIB;
				break;
			case BUTTON_1:
				sServo.uiDesiredPosition=12;
				break;
			case BUTTON_2:
				sServo.uiDesiredPosition=24;
				break;
			case BUTTON_3:
				sServo.uiDesiredPosition=36;
				break;
			case RELEASED:
				break;
			}
	Timer0Interrupts_Init(100000,&Automat);
}
}
