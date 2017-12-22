/**
*\file Board.h
*\author Salvatore Muoio
*/
#ifndef __BOARD_H__
#define __BOARD_H__

/**
*\class Board
*/
class Board
{
	private:
	protected:
	public:
	Board(){};
	virtual void ComputingMax(void) = 0;
	virtual ~Board(void){};
};
// pointer to class Board!!
extern Board *pBoard;
#endif
