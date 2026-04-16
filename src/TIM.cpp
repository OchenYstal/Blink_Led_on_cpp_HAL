#include "TIM.hpp"

TIM::TIM(TIM_TypeDef* instance, TIM_HandleTypeDef& htim) : _instance(instance), _htim(htim) 
{

}

void TIM::Init()
{
    __HAL_RCC_TIM2_CLK_ENABLE();
    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
    _htim.Instance = TIM2;

    _htim.Init.Prescaler = 72000 - 1;
    _htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    _htim.Init.Period = 100 - 1;
    _htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

    HAL_TIM_Base_Init(&_htim);
    HAL_TIM_Base_Start_IT(&_htim);
}

void TIM::Start()
{
    
}

