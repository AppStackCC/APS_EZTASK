/*
	AppStack easy task for Arduino
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
	@Tool 
           - Arduino 1.0.6 on OSX
*/

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "aps_eztask.h"

//Create MY_TASK maximum 10 task
APS_EZTASK MY_TASK(10);

void task_1(void)
{
  Serial.println("task1");
}

void task_2(void)
{
  Serial.println("task_2");
}

void setup()
{
  Serial.begin(9600);

  //add task 
  //add(function name,interval in ms,enable[_TASK_ENABLE_,_TASK_DISABLE_])
  MY_TASK.add(&task_1,500,_TASK_ENABLE_);	//500ms = 0.5s
  MY_TASK.add(&task_2,1000,_TASK_ENABLE_);	//1000ms = 1s
  
  MY_TASK.start();
}

void loop()
{
  MY_TASK.run();
}
