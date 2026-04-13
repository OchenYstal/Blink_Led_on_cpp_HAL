#pragma once
#include "stm32f1xx_hal.h"

class TIM
{
    public:
    TIM(TIM_HandleTypeDef htim, TIM_TypeDef* Instance);
    void Init_TIM();
    void onTimer();

    private:
    TIM_TypeDef* _Instance;
    TIM_HandleTypeDef _htim;
};