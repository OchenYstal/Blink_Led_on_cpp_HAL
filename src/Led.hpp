#pragma once
#include "stm32f1xx_hal.h"

class Led
{
    public:
    Led(GPIO_TypeDef* port, uint32_t pin);
    //Fun for initialize Led's
    void Init();
    //Mode's for Led's
    void toggle();
    void on();
    void off();

    private:
    //Pin/Port for Led's
    GPIO_TypeDef* _port;
    uint32_t _pin;
};