#include "stm32f10x.h"
#include "stm32f10x.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

uint16_t adc_value = 0;  

void delay(void)
{
    volatile uint32_t i;
    for (i = 0; i < 0xFFFFF; i++);
}

void ADC1_Init(void);

int main(void)
{
    ADC1_Init();  
    while (1)
    {
        adc_value = ADC_GetConversionValue(ADC1);
        delay();  
    }
}


void ADC1_Init(void)
{
    GPIO_InitTypeDef gpio;
    ADC_InitTypeDef adc;

  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);


    gpio.GPIO_Pin = GPIO_Pin_0;
    gpio.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &gpio);


    adc.ADC_Mode = ADC_Mode_Independent;
    adc.ADC_ScanConvMode = DISABLE;              
    adc.ADC_ContinuousConvMode = ENABLE;         
    adc.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; 
    adc.ADC_DataAlign = ADC_DataAlign_Right;    
    adc.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &adc);

    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
    ADC_Cmd(ADC1, ENABLE);

    ADC_ResetCalibration(ADC1);
    while (ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1));
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}