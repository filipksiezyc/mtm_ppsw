#include <LPC21xx.H>
#include "led.h"
#define DETECTORSET_bm (1<<10)

enum DetectorState{ACTIVE, INACTIVE};

void DetectorInit(){
	IO0DIR= IO0DIR & (~DETECTORSET_bm);
}	

enum DetectorState eReadDetector(){
	
	if((IO0PIN & DETECTORSET_bm) == 0)
		return ACTIVE;
	else
		return INACTIVE;
	
}	


int main(){
	enum DetectorState a;

	DetectorInit();
	while(1){

	LedStepLeft();
	}
}
