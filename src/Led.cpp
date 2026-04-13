#include "Led.hpp"

Led::Led(GPIO_TypeDef* port, uint32_t pin) : _port(port), _pin(pin) {}

void Led::Init()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef gpio = {0};

    gpio.Pin = _pin;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(_port, &gpio);
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