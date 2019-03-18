// Tools1.h: interface for the Tools class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLS1_H__83D4BE4B_730F_4A51_AD0D_C1CDDE9ABADF__INCLUDED_)
#define AFX_TOOLS1_H__83D4BE4B_730F_4A51_AD0D_C1CDDE9ABADF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdio.h>

void __cdecl OutputDebugStringF(const char *format, ...); 						
						
#ifdef _DEBUG  						
#define DbgPrintf   OutputDebugStringF  						
#else  						
#define DbgPrintf  						
#endif 						


#endif // !defined(AFX_TOOLS1_H__83D4BE4B_730F_4A51_AD0D_C1CDDE9ABADF__INCLUDED_)
