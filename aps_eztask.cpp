/*
  aps_eztask.cpp AppStack easy task for Arduino
  =======
  WEBSITE
  =======
  https://www.facebook.com/appstack.in.th
  http://www.appstack.in.th
  <------------------------------------------------------------------->
  @Author  
           - ultra_mcu@Piak Studiolo LEGO eiei
  @Date 
           - 2015/01/05 , Version 0.1
  @Tool 
           - Arduino 1.0.6 on OSX
*/

#include "Arduino.h"
#include "aps_eztask.h"


APS_EZTASK::APS_EZTASK(uint8_t max)
{
  this->task_max = max;
  this->task = (st_task *)malloc(sizeof(st_task) * max);
  this->running_status = _TRUE_;

}
int APS_EZTASK::add(void (*fn)(void),int interval_ms,int enable)
{

  if(this->task_tail_cnt < this->task_max)
  {
    this->task[this->task_tail_cnt].fn = fn;
    this->task[this->task_tail_cnt].time_interval_ms = interval_ms;
    this->task[this->task_tail_cnt].enable = enable;
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
  if(this->running_status == _TRUE_)
  {
    for(task_cnt_loop = 0; task_cnt_loop < task_tail_cnt; task_cnt_loop++)
    {
      if ((millis() - task[task_cnt_loop].time_cnt) > task[task_cnt_loop].time_interval_ms)
      {
        task[task_cnt_loop].time_cnt = millis();
        if(task[task_cnt_loop].enable == _TASK_ENABLE_)
        {
          (*task[task_cnt_loop].fn)();
        }
      }
    }
  }
}

uint8_t APS_EZTASK::is_running()
{
  return this->running_status;
}

void APS_EZTASK::start()
{
  this->running_status = _TRUE_;
}

void APS_EZTASK::stop()
{
  this->running_status = _FALSE_;
}



