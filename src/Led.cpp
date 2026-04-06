#include "Led.hpp"

Led::Led(GPIO_TypeDef* port, uint32_t pin) : _port(port), _pin(pin) {}

void Led::Init()
{
    if(_port == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
    if(_port == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = _pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(_port, &GPIO_InitStruct);
}

void Led::toggle()
{
    HAL_GPIO_TogglePin(_port, _pin);
}

void Led::on()
{
    HAL_GPIO_WritePin(_port, _pin, GPIO_PIN_SET);
}

void Led::off()
{
    HAL_GPIO_WritePin(_port, _pin, GPIO_PIN_RESET);
}