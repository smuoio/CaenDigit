/**
*\file SharedMemory.h
*\author Salvatore Muoio
*/
#ifndef __SHARED_MEMRY_H__
#define __SHARED_MEMRY_H__
#include <sys/ipc.h>
#include <sys/shm.h>
#include "Constant.h"
#include "Board.h"




namespace shared_memory
{
/*
*\enum e_SharedMemory
*\brief definition of values of the shared memory
*/
    typedef enum
    {
    	SHARED_MEMORY_OK,
    	SHARED_MEMORY_ERROR_SHMGET,
    	SHARED_MEMORY_ERROR_SHMAT,
    }e_SharedMemory;

/*
*\enum e_BoardCaen
*\brief definition of Board used from the Caen
*/
    typedef enum
    {
        Board_X742    = 1,      /*!< borad X742 */
        Board_X752    = 2,      /*!< borad X752 */
        Board_UNKNOWN = 0xFFFF, /*!< borad unknown */
    }e_BoardCaen;
// create the shared memory
    typedef struct
    {
    	types::FLOAT32 Buff[constant::channel_742][constant::events_742];
    }t_DataGroup;	

    typedef struct
    {
    	t_DataGroup DataGroup[2];
    }t_Data742;

    typedef struct
    {
        types::UINT16 Buff[constant::channel_752][constant::events_752]; /*!< data buffer */
    }t_Data752;
    
    typedef struct
    {
   	e_BoardCaen board; /*!< type of board used from the caen */
   	types::INT32 ctrl;
   	types::INT32 master;
   	t_Data742 data742[2];
   	t_Data752 data752;
    }t_sharedmemory;
    
    
}//namespace shared_memory

class SharedMemory 
{
	private:
	key_t key_SharedMemory;
	shared_memory::e_BoardCaen ReadBoard(void);
	static SharedMemory *plShared;
	public:
	SharedMemory();
	static SharedMemory *Instance(void);
	static shared_memory::t_sharedmemory *pSharedMemory;
	shared_memory::t_sharedmemory *getsharedmemory(void) const;
	// debug
	void SetCaenBoard(){pSharedMemory->board = shared_memory::Board_X742;};
	void SetSharedMemory(void);
	// debug
	void CheckBoard(void);
	shared_memory::e_SharedMemory Create_SharedMemory(void);
	virtual ~SharedMemory(void){};
}; //class





#endif
