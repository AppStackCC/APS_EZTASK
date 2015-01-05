
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "aps_eztask.h"


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
  MY_TASK.add(&task_1,500,99);
  MY_TASK.add(&task_2,1000,99);
  
  MY_TASK.set_enable();
}

void loop()
{
  MY_TASK.run();
}
