/**
*\file Mathematic.h
*\brief the file contains the mathematic class
*\author Salvatore Muoio
*/
#ifndef __MATHEMATIC_H__
#define __MATHEMATIC_H__
#include "cmath"
#include "Types.h"
#include "SharedMemory.h"

namespace math
{
	/*
	*\struct e_functionstatus
	*\brief definition of status of function
	*/
	typedef enum
	{
		Unknown,      /*< unknown function*/
		Increrasing,  /*< increasing function*/
		Decreasing,   /*< decreasing function*/
	}e_functionstatus;
}//namespace math


class mathematic: public SharedMemory
{
	private:
	math::e_functionstatus isfunctionincreasing(types::FLOAT32 *pBuff);
	math::e_functionstatus isfunctiondecreasing(types::FLOAT32 *pBuff);
	types::FLOAT32 firstderivative(types::FLOAT32 *pBuff);
	inline types::FLOAT32 SetMax(types::FLOAT32 Max, types::FLOAT32 aVal)
	{
		return( (abs(Max)>abs(aVal)) ? (abs(Max)) : (abs(aVal))) ;
	}
	types::FLOAT32 Max;
	protected:
	public:
	mathematic(){};
	void CheckFunction(void);
	types::INT32 CheckMax(types::FLOAT32 aVal);
	types::FLOAT32 GetMax(void)const;
	void ResetMax(void){ Max = 0;};
	virtual ~mathematic(){};
};


#endif
