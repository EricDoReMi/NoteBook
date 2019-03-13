#ifndef __MYWRAPPERCLASS_H__
#define __MYWRAPPERCLASS_H__
#include <windows.h>
#include "WrapperClass.h"

//基本类型的包装类					
template<class T_BASIC>
class BasicWrapper{
	T_BASIC m_basicTypeValue;
public:
	BasicWrapper(T_BASIC basicTypeValue){
		m_basicTypeValue=basicTypeValue;
	}
	
	void Print(){
		printf("%d\n",m_basicTypeValue);
	}


};

#endif
