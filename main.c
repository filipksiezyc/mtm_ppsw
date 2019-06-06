#include "uart.h"
#include "servo.h"

extern char cOdebranyZnak;
unsigned int uiState=12;



int main(){


	UART_InitWithInt(9600);
	ServoInit(50);
	
			
	while(1){
		switch(cOdebranyZnak){
		
		case '1':
				uiState=uiState%48;
				ServoGoTo(uiState);
				uiState=uiState+12;
				cOdebranyZnak='\0';			
				break;
			
		case 'c' :
			ServoCallib();
			cOdebranyZnak='\0';
			break;
					
		}	
	}	

}
