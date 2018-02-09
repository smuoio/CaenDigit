/**
*\file Mathematic.cpp
*\author Salvatore Muoio
*/

#include "Mathematic.h"
#include "Trace.h"


void mathematic::CheckFunction(void)
{
	//
	math::e_functionstatus functionstatus = math::Unknown;
	// read the data from the shared memory!!!
	trace::TraceInfo("Mathematic::CheckFunction\n", true);
	//read shared memory buffer
}

types::INT32 mathematic::CheckMax(types::FLOAT32 aVal)
{
	// chek max value
	Max = SetMax(Max, aVal);
}

types::FLOAT32 mathematic::GetMax(void)const
{
	return(Max);
}
