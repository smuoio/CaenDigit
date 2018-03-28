/**
*\file Board752.h
*\author Salvatore Muoio
*/
#ifndef __BOARD_752_H__
#define __BOARD_752_H__

#include "Board.h"
class mathematic;

class Board752: public Board
{
	private:
	mathematic *pmath; //fuzzy pointer(pimpl)
	public:
	Board752();
	void ComputingMax(void);
	virtual ~Board752(){};
};


#endif
