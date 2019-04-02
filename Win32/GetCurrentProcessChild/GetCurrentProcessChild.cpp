// GetCurrentProcessChild.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char szBuffer[256] = {0};				
				
	GetCurrentDirectory(256,szBuffer);				
				
	printf("%s\n",szBuffer);				
	
	getchar();
	return 0;
}

