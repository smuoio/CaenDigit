/**
* \file SharedMemory.cpp
* \the file manages all the methods declared in the class Shared Memory
* \Author Salvatore Muoio
*/
#include <iostream>
#include <errno.h>
#include "SharedMemory.h"
#include "Trace.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include "Types.h"
#include "Board742.h"
#include "Board752.h"


using namespace std;
// initialiying of static pointer
SharedMemory* SharedMemory::plShared = 0;
shared_memory::t_sharedmemory * SharedMemory:: pSharedMemory = 0;

SharedMemory::SharedMemory()
{
	key_SharedMemory = 5678;
	trace::TraceInfo("key_SharedMemory", key_SharedMemory);
	//std::cout<<key_SharedMemory<<endl;

}

SharedMemory* SharedMemory::Instance(void)
{
	trace::TraceInfo("SharedMemory::Instance", true);
	if(plShared == 0)
	 plShared = new(SharedMemory);
	return(plShared);
}

shared_memory::e_SharedMemory SharedMemory::Create_SharedMemory(void)
{
	shared_memory::e_SharedMemory lOut = shared_memory::SHARED_MEMORY_OK;
	types::INT32 shmid;
	types::INT32 error;

	SetSharedMemory();

	trace::TraceInfo("Create_SharedMemory::key_SharedMemory", key_SharedMemory);
	trace::TraceInfo("Create_SharedMemory::size of stucture shared memory", sizeof(shared_memory::t_sharedmemory));
	shmid = shmget(key_SharedMemory, sizeof(shared_memory::t_sharedmemory), 0666);
	if(shmid < 0)
	{
	    trace::TraceInfo("Error shmget", shmid);
	    trace::TraceInfo("errno", errno);
	}
	if((pSharedMemory = (shared_memory::t_sharedmemory*)shmat(shmid, NULL, 0)) ==
	   (shared_memory::t_sharedmemory*)-1)
	   lOut = shared_memory::SHARED_MEMORY_ERROR_SHMAT;
	SetCaenBoard();
	trace::TraceInfo("Board Caen", pSharedMemory->board);
	return(lOut);
}

void SharedMemory::SetSharedMemory(void)
{
	types::INT32 shmid;
	shmid = shmget(key_SharedMemory, sizeof(shared_memory::t_sharedmemory), IPC_CREAT | 0666);
	trace::TraceInfo("SetSharedMemory::", shmid);
}

shared_memory::t_sharedmemory* SharedMemory::getsharedmemory(void) const
{
	trace::TraceInfo("SharedMemory::pre_getsharedmemory", true);
	if(pSharedMemory != 0)
	{
		trace::TraceInfo("SharedMemory::post_getsharedmemory", true);
		return(pSharedMemory);
	}
}

void SharedMemory::CheckBoard(void)
{
	trace::TraceInfo("Read Caen Board ", ReadBoard());

	if(ReadBoard() == shared_memory::Board_X742)
	{
		//instantiate the object board 742
		pBoard = new(Board742);
	}
	else if(ReadBoard() == shared_memory::Board_X752)
	{
		//instantiate the object board 752
		pBoard = new(Board752);
	}
}


shared_memory::e_BoardCaen SharedMemory::ReadBoard(void)
{
	return(pSharedMemory->board);
}
