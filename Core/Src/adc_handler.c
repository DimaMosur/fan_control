#include "adc_handler.h"

void ADCHandler_Init(ADC_HandleTypeDef *hadc, ADC_Handler_t *handler)
{
    handler->hadc = hadc;
    
    for (uint8_t i = 0; i < ADC_CHANNELS_COUNT; i++) {
        handler->buffer[i] = 0;
    }
}

void ADCHandler_Start(ADC_Handler_t *handler)
{
    if (handler->hadc != NULL) {
        HAL_ADCEx_Calibration_Start(handler->hadc);
        
        HAL_ADC_Start_DMA(handler->hadc, 
                        (uint32_t*)handler->buffer, 
                        ADC_CHANNELS_COUNT);
    }
}

uint32_t ADCHandler_GetValue(ADC_Handler_t *handler, uint8_t channel_index)
{
    if (channel_index < ADC_CHANNELS_COUNT) {
        return handler->buffer[channel_index];
    }
    return 0;
}

uint32_t ADCHandler_GetNTC1(ADC_Handler_t *handler)
{
    return handler->buffer[ADC_CH_NTC1];
}

uint32_t ADCHandler_GetNTC2(ADC_Handler_t *handler)
{
    return handler->buffer[ADC_CH_NTC2];
}

uint32_t ADCHandler_GetCoreTemp(ADC_Handler_t *handler)
{
    return handler->buffer[ADC_CH_CORE_TEMP];
}