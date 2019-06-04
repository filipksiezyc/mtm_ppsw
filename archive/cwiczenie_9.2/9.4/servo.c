#include <LPC21xx.H>
#include "led.h"
#include "timer_interrupts.h"
#include "servo.h"

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
				
				if(eReadDetector() != ACTIVE){
					LedStepLeft();
				}
					else{
					sServo.eState=IDLE;
					sServo.uiCurrentPosition=0;
					sServo.uiDesiredPosition=0;
				}	
					
				break;
			case IDLE:
					
					if(sServo.uiCurrentPosition != sServo.uiDesiredPosition){
						sServo.eState=IN_PROGRESS;
					}
					else{}
					break;
		case IN_PROGRESS:
					
					if(sServo.uiCurrentPosition<sServo.uiDesiredPosition){
						LedStepLeft();
						sServo.uiCurrentPosition++;
					}
					else if(sServo.uiCurrentPosition>sServo.uiDesiredPosition){
						LedStepRight();
						sServo.uiCurrentPosition--;
					}
					else{
						sServo.eState=IDLE;
					}
					break;
		}
}	

void ServoInit(unsigned int uiServoFrequency){
		unsigned int uiDelayTime=1000000/uiServoFrequency;
		DetectorInit();
		LedInit();
		sServo.eState=CALLIB;
		Timer0Interrupts_Init(uiDelayTime, &Automat);
		while(sServo.eState != IDLE) {}
}	

void ServoCallib(){
	sServo.eState=CALLIB;
	while(sServo.eState != IDLE) {}
}	

void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition=uiPosition;
	sServo.eState = IN_PROGRESS;
	while(sServo.eState != IDLE) {}
}	
