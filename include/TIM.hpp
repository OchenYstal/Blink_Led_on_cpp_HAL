#pragma once
#include "stm32f1xx_hal.h"

class TIM
{
    public:
    TIM(TIM_TypeDef* instance, TIM_HandleTypeDef& htim);
    void Init();
    void Start();
    void Stop();

    TIM_HandleTypeDef* GetHandle() { return &_htim; }

    private:
    TIM_TypeDef* _instance;
    TIM_HandleTypeDef& _htim;
};