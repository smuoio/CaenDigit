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
	types::FLOAT32 MaxBuffer[constant::size_shared][constant::channel_742];
	void SetMaxToChann(types::FLOAT32 const aMax,
		                 types::FLOAT32 *const pMaxBuffer);
	public:
	Board742();
	void ComputingMax(void);
	virtual ~Board742(){};
};


#endif
