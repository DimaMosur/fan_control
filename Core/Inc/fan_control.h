#ifndef FAN_CONTROL_H
#define FAN_CONTROL_H

#include "main.h"

#define FAN_PWM_MAX      2879.0f       
#define FAN_MIN_DUTY     0.42f     
#define FAN_T_OFF        15.0f       
#define FAN_T_MIN        25.0f        
#define FAN_T_MAX        30.0f      

void FanControl_Init(TIM_HandleTypeDef *htim);

float FanControl_CalculateDuty(float temperature);

void FanControl_SetSpeed(float duty);

void FanControl_Update(float temperature);

#endif