#include "uart.h"
#include "servo.h"

extern char cOdebranyZnak;
int uiState=0;



int main(){


	UART_InitWithInt(9600);
	ServoInit(50);
	

	while(1){	
	
	if(cOdebranyZnak != 0){
			switch(cOdebranyZnak){
			
				case '1':
					if(uiState%48 == 36){
						ServoCallib();
						uiState=uiState+12;
					}
					else{
						uiState=uiState+12;
						ServoGoTo(uiState%48);
					}			
					break;
			
				case '2':
					if(uiState==0){
					uiState=36;
					ServoGoTo(uiState);
					}
					else{
						uiState=uiState-12;
						ServoGoTo(uiState%48);
					}
					break;
		
				case '3' :
					ServoGoTo(36);
					uiState=36;
					break;
			
				case 'c' :
					ServoCallib();
					uiState=12;
					break;		
				
			
			}
			cOdebranyZnak='\0';
		}
			
	}	
}
