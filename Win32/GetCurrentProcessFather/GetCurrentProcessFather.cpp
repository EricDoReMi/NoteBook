// GetCurrentProcessFather.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
	STARTUPINFO ie_si = {0};   						
	PROCESS_INFORMATION ie_pi;						
	ie_si.cb = sizeof(ie_si);						
							
							
	TCHAR szBuffer[256] = "C:\\GetCurrentProcessChild.exe";						
	CreateProcess(						
		NULL,                    // name of executable module					
		szBuffer,                      		    // command line string			
		NULL, 		    // SD			
		NULL,  		    // SD			
		FALSE,                      		    // handle inheritance option			
		CREATE_NEW_CONSOLE,     		    // creation flags  			
		NULL,                    // new environment block					
		"C:\\",                    // current directory name					
		&ie_si,                  // startup information					
		&ie_pi                   // process information					
		);					
						

	
	return 0;
}

