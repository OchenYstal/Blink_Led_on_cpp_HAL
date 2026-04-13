#include "TIM.hpp"

TIM::TIM(TIM_HandleTypeDef htim, TIM_TypeDef* Instance) : _htim(htim), _Instance(Instance)  {}

void TIM::Init_TIM()
{
    __HAL_RCC_TIM2_CLK_ENABLE();
    _htim.Instance = _Instance;

    _htim.Init.Prescaler = 72000 - 1;
    _htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    _htim.Init.Period = 100 - 1;
    _htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

    HAL_TIM_Base_Init(&_htim);
    HAL_TIM_Base_Start_IT(&_htim);
    if(_Instance == TIM2)
    {
        HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(TIM2_IRQn);
    }
}
void TIM::onTimer()
{}

