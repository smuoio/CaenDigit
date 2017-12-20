/**
*\file Board742.cpp
*\author Salvatore Muoio
*/
#include "Board742.h"
#include "Trace.h"

Board742::Board742(void)
{
	trace::TraceInfo("Board742::constructor\n", true);
	pmath = new(mathematic);
}

void Board742::ComputingMax(void)
{
	shared_memory::t_sharedmemory *pshared;
	trace::TraceInfo("Board742::computingMax\n", true);
	pshared = getsharedmemory();
	pmath->CheckFunction();
}


