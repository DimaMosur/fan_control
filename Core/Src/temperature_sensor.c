#include "temperature_sensor.h"
#include <math.h>

float TemperatureSensor_CalculateNTC(uint32_t adc_value)
{
    float voltage = (adc_value * VREF) / ADC_MAX;
    
    if (voltage >= VREF || voltage <= 0.01f) {
        return 0.0f;  
    }
    
    float r_ntc = R_FIXED * (voltage / (VREF - voltage));
    
    float temperature = (1.0f / ((1.0f / T0) + (1.0f / BETA) * logf(r_ntc / R0))) - 273.15f;
    
    return temperature;
}

float TemperatureSensor_CalculateCore(uint32_t adc_value)
{
    float voltage = (adc_value * VREF) / ADC_MAX;
    
    float temperature = ((CORE_TEMP_V25 - voltage) / CORE_TEMP_SLOPE) + CORE_TEMP_OFFSET;
    
    return temperature;
}

float TemperatureSensor_GetMax(float temp1, float temp2)
{
    return (temp1 > temp2) ? temp1 : temp2;
}