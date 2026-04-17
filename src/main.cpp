#include "stm32f1xx_hal.h"
#include "Led.hpp"
#include "TIM.hpp"
#include "ButtonInterupt.hpp"
#include "UART.hpp"
volatile uint32_t flag = 0;
volatile uint32_t counter = 0;
TIM_HandleTypeDef htim2;
volatile uint32_t timer_flag = 0;

Button button(GPIOA, GPIO_PIN_0);

TIM timer2(TIM2, htim2);

int main(void) {
    HAL_Init();   
    Led blueLed(GPIOC, GPIO_PIN_13);
    hal::UART usart1(USART1, 115200,
                     GPIOA, GPIO_PIN_9,
                     GPIOA, GPIO_PIN_10);
    usart1.init();
    timer2.Init();
    blueLed.Init();
    button.init();
    
    while(1) 
    {   
        if(timer_flag)
        {
            timer_flag = 0;
            blueLed.toggle();
            usart1.sendString("Toggle LED's pins\r\n");
        }      
    }
}

extern "C" void SysTick_Handler(void) 
{
    HAL_IncTick();
}

extern "C" void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_0)
    {
        flag = 1;
    }
}
extern "C" void EXTI0_IRQHandler(void) 
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

extern "C" void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&htim2);
}

extern "C" void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) 
{
    counter += 10;
    if(htim->Instance == TIM2) 
    {
        if(counter % 50 == 0)
        {
            timer_flag = 1;
        }
    }
}


