/*
	aps_eztask.h AppStack easy task for Arduino
  =======
  WEBSITE
  =======
  https://www.facebook.com/appstack.in.th
  http://www.appstack.in.th
  <------------------------------------------------------------------->
	@Author  
           - ultra_mcu@Piak Studiolo LEGO eiei
	@Date 
           - 2015/01/07 , Version 0.2a
           - 2015/01/07 , Version 0.2
           - 2015/01/07 , Version 0.1c
           - 2015/01/05 , Version 0.1
	@Tool 
           - Arduino 1.0.6 on OSX
*/
	
#ifndef _APS_EZTASK_H_
#define _APS_EZTASK_H_

#include "Arduino.h"
#include <stdint.h>


#define _TASK_ENABLE_ 99
#define _TASK_DISABLE_ 0


#define _TRUE_ 1
#define _FALSE_ 0

typedef struct 
{
  void (*fn)(void);
  uint32_t time_cnt;
  uint32_t time_interval_ms;
  uint8_t enable;
  
}st_task;

class APS_EZTASK
{
  public:
    APS_EZTASK(uint8_t max);
    int add(void (*fn)(void),int interval_ms,int enable);
    int set_interval(int index,int interval_ms);
    int get_interval(int index);
    uint8_t is_running();
    void run();
    void start();
    void stop();

  private:
    st_task *task;
    uint8_t task_tail_cnt;
    uint8_t running_status;
    uint8_t task_cnt_loop;
    uint8_t task_max;

};

#endif