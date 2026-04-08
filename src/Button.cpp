#include "Button.hpp"

Button::Button(GPIO_TypeDef* port, uint16_t pin) : _port(port), _pin(pin) {}

void Button::init()
{
    if(_port == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
    if(_port == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = _pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(_port, &GPIO_InitStruct);
    HAL_NVIC_SetPriority(EXTI0_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

bool Button::isPressed()
{
    return HAL_GPIO_ReadPin(_port, _pin) != GPIO_PIN_RESET;
}