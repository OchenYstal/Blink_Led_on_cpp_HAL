#pragma once
#include "stm32f1xx_hal.h"

class Button
{
    public:
    Button(GPIO_TypeDef* port, uint16_t pin);
    //Initialize button
    void init();
    bool isPressed();
    private:
    //Port/Pin for button
    GPIO_TypeDef* _port;
    uint16_t _pin;
};