#include "led.h"
#include "keyboard.h"
#include "timer.h"

		
int main(){
	InitTimer0Match0(100000);
	LedInit();
	//przesunie LED0 na LED1
	while(1){
		LedStepLeft();
		WaitOnTimer0Match0();
	}
}
