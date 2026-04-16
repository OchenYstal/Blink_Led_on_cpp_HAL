#include "ButtonInterupt.hpp"

Button::Button(GPIO_TypeDef* port, uint16_t pin) : _port(port), _pin(pin) { }

void Button::init()
{
    __HAL_RCC_AFIO_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef gpio = {0};

    gpio.Pin = _pin;
    gpio.Mode = GPIO_MODE_IT_FALLING;  
    gpio.Pull = GPIO_PULLDOWN;           
    HAL_GPIO_Init(_port, &gpio);
    
    // ==== NVIC для кнопки ====
    HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

bool Button::isPressed()
{
    return HAL_GPIO_ReadPin(_port, _pin) == GPIO_PIN_RESET;
}

