#include <iostream>
#include <string.h>
#include "Debug.h"
#include "SharedMemory.h"
#include "Trace.h"

using namespace std;
trace::e_tracelevel leveltrace;
std::ofstream logfile ("log_shared_ememory.txt",std::ofstream::out);
int main (void)
{
	// set level of logging
  log(trace::info) << "foo:" <<"bar:" << "baz:";
	SharedMemory& pShared = SharedMemory::Instance();
	int debug = debug_state::NO_DEBUG_STATE;// debug variable
	std::cout<<"Set Debug for data: =";
	std::cin>>debug_state::udebugstate.usdebugstate;//debug;
	//std::cin
	if (pShared.Create_SharedMemory() == shared_memory::SHARED_MEMORY_OK)
	{
		/*
		memset((pShared->getsharedmemory())->data742, 0,
		       sizeof(shared_memory::t_Data742));
		*/
		//todo
		trace::TraceInfo("create shared memory ok", true);
		// fill shared memory
		if(debug_state::udebugstate.debugstate.debug_data == debug_state::DEBUG_STATE_DATA)
		{
			for(int ii = 0; ii < 2; ii++)
				for(int jj = 0; jj < 1024; jj++)
			(pShared.getsharedmemory())->data742[ii].DataGroup[ii].Buff[ii][jj] = jj;
		}
		// fill shared memory
	}
	// check the board!!!!
	// in according with the board we have to instantiate the correct object
	pShared.CheckBoard();
	{
		pBoard->ComputingMax();// compute the max!!!
	}
	return 0;
}
