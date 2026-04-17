#include "UART.hpp"

namespace hal
{
    UART::UART(USART_TypeDef* instance, uint32_t baudrate,
            GPIO_TypeDef* tx_port, uint16_t tx_pin,
            GPIO_TypeDef* rx_port, uint16_t rx_pin) 
            : _instance(instance), baud(baudrate), _tx_pin(tx_pin), _tx_port(tx_port), _rx_pin(rx_pin), _rx_port(rx_port) {}

    void UART::configureGPIO()
    {
        __HAL_RCC_USART1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        GPIO_InitTypeDef GPIO_InitStruct = {0};

        GPIO_InitStruct.Pin = _tx_pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(_tx_port, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = _rx_pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;      // 
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(_rx_port, &GPIO_InitStruct);
    }
    void UART::init()
    {
        configureGPIO();
        usart.Instance = _instance;
        usart.Init.BaudRate = baud;
        usart.Init.WordLength = UART_WORDLENGTH_8B;
        usart.Init.StopBits = UART_STOPBITS_1;
        usart.Init.Parity = UART_PARITY_NONE;
        usart.Init.Mode = UART_MODE_TX_RX;
        //usart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
        //usart.Init.OverSampling = UART_OVERSAMPLING_16;
        HAL_USART_Init(&usart);
    }
    
    void UART::sendString(const char* str)
    {
        HAL_USART_Transmit(&usart, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
    }
}

