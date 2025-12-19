#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "main.h"

#define VREF            3.3f
#define ADC_MAX         4095.0f
#define R_FIXED         10000.0f
#define R0              10000.0f
#define BETA            3950.0f
#define T0              298.15f

#define CORE_TEMP_V25   1.43f
#define CORE_TEMP_SLOPE 0.0043f
#define CORE_TEMP_OFFSET 25.0f

float TemperatureSensor_CalculateNTC(uint32_t adc_value);

float TemperatureSensor_CalculateCore(uint32_t adc_value);

float TemperatureSensor_GetMax(float temp1, float temp2);

#endif