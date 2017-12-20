/**
*\file Mathematic.h
*\author Salvatore Muoio
*/
#ifndef __MATHEMATIC_H__
#define __MATHEMATIC_H__
#include "Types.h"
#include "SharedMemory.h"

namespace math
{
	typedef enum
	{
		Unknown,
		Increrasing,
		Decreasing,
	}e_functionstatus;
}//namespace math


class mathematic: public SharedMemory
{
	private:
	math::e_functionstatus isfunctionincreasing(types::FLOAT32 *pBuff);
	math::e_functionstatus isfunctiondecreasing(types::FLOAT32 *pBuff);
	types::FLOAT32 firstderivative(types::FLOAT32 *pBuff);
	protected:
	public:
	mathematic(){};
	void CheckFunction(void);
	virtual ~mathematic(){};
};


#endif
