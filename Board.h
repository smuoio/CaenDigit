/**
*\file Board.h
*\author Salvatore Muoio
*/
#ifndef __BOARD_H__
#define __BOARD_H__

/**
*\class Board
*\brief the class is the interface to other Caen board.
*\      the class is built with pure virtual function
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
/**
*\var Board *pBoard
*\brief pointer to class interface
*/
extern Board *pBoard;
#endif
