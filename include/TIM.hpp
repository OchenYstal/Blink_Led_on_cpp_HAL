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
    // Для того что бы не копировать _htim и использовать по ссылке в функции "C"
    TIM_HandleTypeDef& _htim;
};