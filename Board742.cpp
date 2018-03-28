/**
*\file Board742.cpp
*|brief implementation of all methods relative to board 742
*\author Salvatore Muoio
*/
#include "Board742.h"
#include "Mathematic.h"
#include "Trace.h"

Board742::Board742(void)
{
	trace::TraceInfo("Board742::constructor\n", true);
	pmath = new(mathematic);
}

void Board742::SetMaxToChann(types::FLOAT32  const aMax,
									           types::FLOAT32 *const pMaxBuffer)
{
	if(pMaxBuffer != 0)
	{
		*pMaxBuffer = aMax;
		// clean max value
		//*aMax = 0;
		pmath->ResetMax();
	}
}


void Board742::ComputingMax(void)
{
	shared_memory::t_sharedmemory *pshared;
	trace::TraceInfo("Board742::computingMax\n", true);
	pshared = getsharedmemory();
	pmath->CheckFunction();
	types::INT32 smIndex = ((pshared->ctrl)%2);
	/* read all data....*/
	for(int ii = 0; ii < 2; ii++)
	{
		for(int jj = 0; jj < constant::channel_742; jj++)
		{
			for(int tt = 0; tt < constant::events_742; tt++)
			{
				// check max
				pmath->CheckMax(pshared->data742[smIndex].DataGroup[ii].Buff[jj][tt]);
			}//for tt
			//trace::TraceInfo("Max relative = \n",pmath->GetMax());
			// set the max for each channel
			SetMaxToChann(pmath->GetMax(), &MaxBuffer[ii][jj]);
		}// for jj
	}//for ii
}
