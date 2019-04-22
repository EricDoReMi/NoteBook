// Tools.h: interface for the Tools class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLS_H__250A963F_D965_4D80_86FB_5664350423E3__INCLUDED_)
#define AFX_TOOLS_H__250A963F_D965_4D80_86FB_5664350423E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

void __cdecl OutputDebugStringF(const char *format, ...); 

#ifdef _DEBUG  
#define DbgPrintf   OutputDebugStringF  
#else  
#define DbgPrintf  
#endif 


#endif // !defined(AFX_TOOLS_H__250A963F_D965_4D80_86FB_5664350423E3__INCLUDED_)
