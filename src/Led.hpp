#pragma once
#include "stm32f1xx_hal.h"

class Led
{
    public:
    Led(GPIO_TypeDef* port, uint32_t pin);
    void Init();
    void toggle();
    void on();
    void off();

    private:
    GPIO_TypeDef* _port;
    uint32_t _pin;
};