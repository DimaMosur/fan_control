#ifndef ADC_HANDLER_H
#define ADC_HANDLER_H

#include "main.h"

#define ADC_CHANNELS_COUNT    3

#define ADC_CH_NTC1           0
#define ADC_CH_NTC2           1
#define ADC_CH_CORE_TEMP      2

typedef struct {
    uint16_t buffer[ADC_CHANNELS_COUNT];
    ADC_HandleTypeDef *hadc;
} ADC_Handler_t;

void ADCHandler_Init(ADC_HandleTypeDef *hadc, ADC_Handler_t *handler);

void ADCHandler_Start(ADC_Handler_t *handler);

uint32_t ADCHandler_GetValue(ADC_Handler_t *handler, uint8_t channel_index);

uint32_t ADCHandler_GetNTC1(ADC_Handler_t *handler);

uint32_t ADCHandler_GetNTC2(ADC_Handler_t *handler);

uint32_t ADCHandler_GetCoreTemp(ADC_Handler_t *handler);

#endif