/*
	aps_eztask.h AppStack easy task for Arduino
  =======
  WEBSITE
  =======
  https://www.facebook.com/appstack.in.th
  http://www.appstack.in.th
  <------------------------------------------------------------------->
	@Auther  
           - ultra_mcu@Piak Studiolo LEGO eiei
	@Date 
           - 2015/01/05 , Version 0.1b
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
  uint8_t in_service;
  
}st_task;

class APS_EZTASK
{
  public:
    APS_EZTASK(uint8_t max);
    int add(void (*fn)(void),int interval_ms,int in_service);
    void run();
    uint8_t is_enable();
    void set_enable();
    void set_disable();

  private:
    st_task *task;
    uint8_t task_tail_cnt;
    uint8_t task_enable_all;
    uint8_t task_cnt_loop;
    uint8_t task_max;

};

#endif