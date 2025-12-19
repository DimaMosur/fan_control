#include "fan_control.h"

static TIM_HandleTypeDef *fan_htim = NULL;
static uint32_t fan_channel = TIM_CHANNEL_1;

void FanControl_Init(TIM_HandleTypeDef *htim)
{
    fan_htim = htim;
    
    if (fan_htim != NULL) {
        HAL_TIM_PWM_Start(fan_htim, fan_channel);
        __HAL_TIM_SET_COMPARE(fan_htim, fan_channel, (uint32_t)(FAN_PWM_MAX * 0.5f));
    }
}

float FanControl_CalculateDuty(float temperature)
{
    if (temperature < FAN_T_OFF) {
        return 0.0f;
    }
    else if (temperature < FAN_T_MIN) {
        return FAN_MIN_DUTY;
    }
    else if (temperature >= FAN_T_MAX) {
        return 1.0f;
    }
    else {
        float k = (temperature - FAN_T_MIN) / (FAN_T_MAX - FAN_T_MIN);
        return FAN_MIN_DUTY + k * (1.0f - FAN_MIN_DUTY);
    }
}

void FanControl_SetSpeed(float duty)
{
    if (fan_htim == NULL) {
        return; 
    }
    
    if (duty < 0.0f) duty = 0.0f;
    if (duty > 1.0f) duty = 1.0f;
    
    uint32_t pwm_value = (uint32_t)(duty * FAN_PWM_MAX);
    __HAL_TIM_SET_COMPARE(fan_htim, fan_channel, pwm_value);
}

void FanControl_Update(float temperature)
{
    float duty = FanControl_CalculateDuty(temperature);
    FanControl_SetSpeed(duty);
}