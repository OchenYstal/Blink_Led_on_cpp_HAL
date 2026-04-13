#include "stm32f1xx_hal.h"
#include "Led.hpp"
#include "ButtonInterupt.hpp"
volatile uint32_t flag = 0;
Button button(GPIOA, GPIO_PIN_0);
    Led led1(GPIOA, GPIO_PIN_1);     
    Led led9(GPIOA, GPIO_PIN_9);  
    Led blueLed(GPIOB, GPIO_PIN_2); 
    
int main(void) {
    HAL_Init();
    blueLed.Init();
    led1.Init();
    led9.Init();
    button.init();
    while(1) 
    {   if(flag)
        {
            flag = 0;
            blueLed.toggle();
            led1.toggle();
            led9.toggle(); 
            HAL_Delay(50); 
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
