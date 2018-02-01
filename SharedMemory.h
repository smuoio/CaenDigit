/**
*\file SharedMemory.h
* \the file manages all the methods declared in the class Shared Memory
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
    	SHARED_MEMORY_OK,          /*!< creation shared memory without error*/
    	SHARED_MEMORY_ERROR_SHMGET,/*!< error in the creation shared memory*/
    	SHARED_MEMORY_ERROR_SHMAT,/*!< error in the attach the pointer to the shared memory*/
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
    /*
    *\struct t_DataGroup
    *\brief definition float used for the X742 board
    */
    typedef struct
    {
    	types::FLOAT32 Buff[constant::channel_742][constant::events_742]; /*!< float */
    }t_DataGroup;
    /*
    *\struct t_Data742
    *\brief definition of structure used for the X742 board
    */
    typedef struct
    {
    	t_DataGroup DataGroup[constant::size_shared]; /*!< DataGroup */
    }t_Data742;
    /*
    *\struct t_Data752
    *\brief definition of structure used for the Board_X752 board
    */
    typedef struct
    {
        types::UINT16 Buff[constant::channel_752][constant::events_752]; /*!< data buffer */
    }t_Data752;
    /*
    *\struct t_sharedmemory
    *\brief definition of structure of shared memory
    */
    typedef struct
    {
   	  e_BoardCaen board;    /*!< type of board used from the caen */
   	  types::INT32 ctrl;    /*!< type control  */
   	  types::INT32 master;  /*!< type master */
   	  t_Data742 data742[constant::size_shared]; /*!< type data 742 board */
   	  t_Data752 data752[constant::size_shared]; /*!< type data 752 board */
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
	void SetCaenBoard(void){pSharedMemory->board = shared_memory::Board_X742;};
	void SetSharedMemory(void);
  void CreateData(void);
	// debug
	void CheckBoard(void);
	shared_memory::e_SharedMemory Create_SharedMemory(void);
	virtual ~SharedMemory(void){};
}; //class


#endif
