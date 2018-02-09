#include <iostream>
#include "SharedMemory.h"
#include "Trace.h"

using namespace std;

int main (void)
{
	SharedMemory *pShared = SharedMemory::Instance();
	int debug = 0;
	std::cin>>debug;
	if (pShared->Create_SharedMemory() == shared_memory::SHARED_MEMORY_OK)
	{
		//todo
		trace::TraceInfo("create shared memory ok", true);
		// fill shared memory
		if(debug)
		{
			for(int ii = 0; ii < 2; ii++)
				for(int jj = 0; jj < 1024; jj++)
			(pShared->getsharedmemory())->data742[ii].DataGroup[ii].Buff[ii][jj] = jj;
		}
		// fill shared memory
	}
	// check the board!!!!
	// in according with the board we have to instantiate the correct object
	pShared->CheckBoard();
	{
		pBoard->ComputingMax();
	}
	return 0;
}
