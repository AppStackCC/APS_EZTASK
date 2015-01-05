/*
  aps_eztask.cpp AppStack easy task for Arduino
  =======
  WEBSITE
  =======
  https://www.facebook.com/appstack.in.th
  http://www.appstack.in.th
  <------------------------------------------------------------------->
  @Auther  - ultra_mcu[at]msn[dot]com 
           - https://www.facebook.com/piakstudio
  @Date 
           - 2015/01/05 , Version 0.1b
  @Tool 
           - Arduino 1.0.6 on OSX
*/

#include "Arduino.h"
#include "aps_eztask.h"


APS_EZTASK::APS_EZTASK(uint8_t max)
{
  this->task_max = max;
  this->task = (st_task *)malloc(sizeof(st_task) * max);

}
int APS_EZTASK::add(void (*fn)(void),int interval_ms,int in_service)
{

  if(this->task_tail_cnt < this->task_max)
  {
    this->task[this->task_tail_cnt].fn = fn;
    this->task[this->task_tail_cnt].time_interval_ms = interval_ms;
    this->task[this->task_tail_cnt].in_service = in_service;
    this->task_tail_cnt++;
    
    return _TRUE_;
  }
  else
  {
    return _FALSE_;
  }
  
}

void APS_EZTASK::run()
{
  for(task_cnt_loop = 0; ((task_cnt_loop < task_tail_cnt) && (task_enable_all == _TRUE_)); task_cnt_loop++)
  {
      if ((millis() - task[task_cnt_loop].time_cnt) > task[task_cnt_loop].time_interval_ms)
      {
        task[task_cnt_loop].time_cnt = millis();
        if(task[task_cnt_loop].in_service == _TASK_ENABLE_)
        {
          (*task[task_cnt_loop].fn)();
        }
      }
  }
}

uint8_t APS_EZTASK::is_enable()
{
  return task_enable_all;
}

void APS_EZTASK::set_enable()
{
  task_enable_all = _TRUE_;
}

void APS_EZTASK::set_disable()
{
  task_enable_all = _FALSE_;
}



