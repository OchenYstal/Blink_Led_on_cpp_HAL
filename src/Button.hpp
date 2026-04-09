#pragma once
#include "stm32f1xx_hal.h"

class Button
{
    public:
    Button(GPIO_TypeDef* port, uint16_t pin);
    //Initialize button
    void init();
    //
    void onPress();
    //checks connecting pins
    bool matches(uint16_t triggerPin) const;

    private:
    //Port/Pin for button
    GPIO_TypeDef* _port;
    uint16_t _pin;
    static void globalDispatch(uint16_t pin)
    {
        for(auto btn : buttonList)
        {
            if(btn && btn->matches(pin))
            {
                btn->onPress();
            }
        }
    }
    static Button* buttonList[16];
    static int buttonCount;

    void registerButton(Button* btn);
    friend void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
};