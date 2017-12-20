/**
*\file Board742.h
*\author Salvatore Muoio
*/

#ifndef __BOARD_742_H__
#define __BOARD_742_H__

#include "Board.h"
#include "Mathematic.h"
#include "SharedMemory.h"

class Board742: public Board, public SharedMemory
{
	private:
	mathematic *pmath; //fuzzy pointer(pimpl)
	public:
	Board742();
	void ComputingMax(void);
	virtual ~Board742(){};
};


#endif
