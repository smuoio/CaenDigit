/**
*\file Debug.h
*\author Salvatore Muoio
*/
#ifndef __DEBUG_H__
#define __DEBUG_H__

namespace debug_state
{
  typedef enum
  {
    NO_DEBUG_STATE,
    DEBUG_STATE_DATA,
    DEBUG_SHARED_MEMORY_ACTIVE,
  }e_level_debug;

  typedef struct
  {
    unsigned short debug_data:1,
                 debug_shared_memory_active:1,
                 spare:14;
  }t_debug_state;
  union u_debug_state
  {
    t_debug_state debugstate;
    unsigned short usdebugstate;
  }udebugstate;

}




#endif
