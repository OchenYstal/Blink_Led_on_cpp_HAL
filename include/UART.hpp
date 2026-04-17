#pragma once
#include <cstring>
#include "stm32f1xx_hal.h"

namespace hal
{
    class UART
    {
    public:
    UART(USART_TypeDef* instance, uint32_t baudrate,
         GPIO_TypeDef* tx_port, uint16_t tx_pin,
         GPIO_TypeDef* rx_port, uint16_t rx_pin);
    void init();
    void sendString(const char* str);

    private:
    USART_HandleTypeDef usart;
    USART_TypeDef* _instance;
    uint32_t baud;

    GPIO_TypeDef* _tx_port;
    uint16_t _tx_pin;
    GPIO_TypeDef* _rx_port;
    uint16_t _rx_pin;   

    void configureGPIO();
    };
}