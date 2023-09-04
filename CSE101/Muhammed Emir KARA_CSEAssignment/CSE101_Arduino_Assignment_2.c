#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include <Windows.h>
/*Windows API functions (File
my sources
https://learn.microsoft.com/en-us/windows/win32/api/fileapi/
https://social.msdn.microsoft.com/Forums/sqlserver/en-US/35ed4698-c989-4eb5-808c-a39f14d255a4/serial-comm-with-arduino?forum=vcgeneral
https://forum.arduino.cc/t/serial-communication-between-pc-and-arduino-unpredictable/108385
...

I used do while because ý want to execute code at least one time even if it doesn't provide the condition
The conio.h header file 
*/
int main()
{
	//Determining some parameters
    HANDLE handCom;                     
    char ComPort[] = "\\\\.\\COM3"; // UNO's port name is COM3
    BOOL State;                       
    DWORD dwEventMask;                  
    char Reader;                 
    char Reader_Button;
    char Stor[256];           
    char Stor_Button[256];
    DWORD NoBytesRead;                
    char sender[10];
    char sender_square[10];
    char sender_button[10];
    int i=0;

    // Opening the Serial Port 

    handCom = CreateFile(ComPort,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);                        

    // Setting the Parameters for the SerialPort

    DCB dcbSerialParams = {0}; 
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    State = GetCommState(handCom, &dcbSerialParams); 

    dcbSerialParams.BaudRate = CBR_9600;   
    dcbSerialParams.ByteSize = 8;          
    dcbSerialParams.StopBits = ONESTOPBIT; 
    dcbSerialParams.Parity = NOPARITY;     

    State = SetCommState(handCom, &dcbSerialParams);

    // Setting Timeouts

    COMMTIMEOUTS timeouts = {0};
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    //Checking time out
    if (SetCommTimeouts(handCom, &timeouts) == FALSE)
        printf("\n\n    Error! in Setting Time Outs");

   // Setting Receive Mask

    State = SetCommMask(handCom, EV_RXCHAR); //Configure Windows for Character Reception

	//MENU
	printf("##      WELCOME TO GTU ARDUINO LAB    ##\n");
	printf("## STUDENT NAME: MUHAMMED EMIR KARA ##\n");
	printf("##  PLEASE SELECT FROM THE FOLLOWING  ##\n");
	printf("##                MENU :              ##\n");
	printf("(1) TURN ON LED ON ARDUINO\n");
	printf("(2) TURN OFF LED ON ARDUINO\n");
	printf("(3) FLASH ARDUINO LED 3 TIMES\n");
	printf("(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n");
	printf("(5) Button press counter\n");
	printf("(0) EXIT\n");

    // Comminicates through Port
	do{
    	printf("PLEASE SELECT:");
    	scanf("%s",&sender[0]);
    	DWORD dNoOFBytestoWrite;    
    	DWORD dNoOfBytesWritten = 0; 
    	dNoOFBytestoWrite = sizeof(sender);

    	State = WriteFile(handCom,sender,dNoOFBytestoWrite,&dNoOfBytesWritten,NULL);
    	// Checking User's input
        if(sender[0] != '0' && sender[0] != '1' && sender[0] != '2' && sender[0] != '3' && sender[0] != '4' && sender[0] != '5' ) 
		printf("TRY AGAIN. \n");  
		//Arduino square     	
    	if(sender[0]=='4'){
    		printf("Please write a number to compute square:");
			scanf("%s",&sender_square[0]);
			
			State = WriteFile(handCom,sender_square,dNoOFBytestoWrite,&dNoOfBytesWritten,NULL);
	
        	do{
            	State = ReadFile(handCom, &Reader, sizeof(Reader), &NoBytesRead, NULL);// Reading the square output on Port
            	Stor[i] = Reader;     
            	i++;
        	} while (NoBytesRead > 0);

        // Printing Arduino square output 
        printf("The result calculated by arduino is: ");
        int j = 0;
        for (j = 0; j < i - 1; j++) 
            printf("%c",Stor[j]);
        i=0;
    	}
		//button
    	if(sender[0]=='5'){
    		while(1){
    			printf("Write 1 to see button counter output(0 to back menu):");
            	scanf("%s",&sender_button[0]);
            
            	if(sender_button[0]=='0')
					break; 
					
         		State = WriteFile(handCom,sender_button,dNoOFBytestoWrite,&dNoOfBytesWritten,NULL);
    			do{
            		State = ReadFile(handCom, &Reader_Button, sizeof(Reader_Button), &NoBytesRead, NULL);//We read button count on Port
            		Stor_Button[i] = Reader_Button;
            		i++;
        		} while (NoBytesRead > 0);
        		int j = 0;
        		for (j = 0; j < i - 1; j++)
            		printf("%c",Stor_Button[j]);
         		i=0;
    
        // Printing output
        		printf("\n\n    ");
        		for (j = 0; j < i - 1; j++) 
            		printf("%c",Stor_Button[j]); 
			} 
   		}
		//Terminating Program
        if(sender[0]=='0'){
 			printf("PROGRAM TERMINATED\n");
			CloseHandle(handCom);  
			break;} //Closing the Serial Port             
    }while(sender[0]!='0');
    return 0;
} 
