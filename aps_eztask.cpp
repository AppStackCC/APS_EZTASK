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
           - 2015/01/07 , Version 0.2a
           - 2015/01/07 , Version 0.2
           - 2015/01/07 , Version 0.1c
           - 2015/01/05 , Version 0.1
  @Tool 
           - Arduino 1.0.6 on OSX
*/

#include "Arduino.h"
#include "aps_eztask.h"


APS_EZTASK::APS_EZTASK(uint8_t max)
{
  if(max == 0)
  {
    max = 1;
  }

  this->task_max = max;
  this->task_tail_cnt = 0;
  this->task = (st_task *)malloc(sizeof(st_task) * max);
  memset(this->task,0,sizeof(st_task) * max);
  
  stop();

}

int APS_EZTASK::add(void (*fn)(void),int interval_ms,int enable)
{

  uint8_t index = 0;
  if(this->task_tail_cnt < this->task_max)
  {
    index = this->task_tail_cnt;
    this->task[this->task_tail_cnt].fn = fn;
    this->task[this->task_tail_cnt].time_interval_ms = interval_ms;
    this->task[this->task_tail_cnt].enable = enable;
    this->task_tail_cnt++;
    
    return index;
  }

  
  return -1;
  
  
}

int APS_EZTASK::set_interval(int index,int interval_ms)
{

  if(index < this->task_max)
  {
    this->task[index].time_interval_ms = interval_ms;
    
    return _TRUE_;
  }


  return _FALSE_;
  
}

int APS_EZTASK::get_interval(int index)
{

  if(index < this->task_max)
  {
    return this->task[index].time_interval_ms;
  }
  
  return -1;
  
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



