#include <iostream>
#include "SharedMemory.h"
#include "Trace.h"
//#include "Board742.h"
//#include "Board752.h"

using namespace std;

int main (void)
{
	SharedMemory *pShared = SharedMemory::Instance();
	int debug = 0;
	if (pShared->Create_SharedMemory() == shared_memory::SHARED_MEMORY_OK)
	{
		//todo
		trace::TraceInfo("create shared memory ok", true);
	}
	// check the board!!!!
	// in according with the board we have to instantiate the correct object
	pShared->CheckBoard();
	{
		pBoard->ComputingMax();
	}
	std::cin>>debug;
	return 0;
}
