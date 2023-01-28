#ifndef __LIBRARY_OOP_H__
#define __LIBRARY_OOP_H__

#include "Atomic/Atomic.h"
#include "Object/Object.h"
#include "AnonymousObject/AnonymousObject.h"

#ifdef _WIN32
	#ifdef _WIN64
		#pragma comment(lib, "oop/oop.lib")		
	#endif
	#ifdef WIN32
		#pragma comment(lib, "oop/oop32.lib")
	#endif
#endif

#endif //__LIBRARY_OOP_H__
