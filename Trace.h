/**
*\file Trace.h
*\author Salvatore Muoio
*/
#ifndef __TRACE_H__
#define __TRACE_H__
#include <iostream>

namespace trace
{
	typedef enum
	{
		basic, 
		verbose,
	}e_tracelevel;

	template <class TraceString, class TraceType> void TraceInfo(TraceString &string, TraceType info)
	{
		std::cout<<string;
		std::cout<<" "<<info<<std::endl;
	}

}//namespace

class Trace
{
	public:
	Trace(void){};
	virtual ~Trace(void){};
};

#endif
