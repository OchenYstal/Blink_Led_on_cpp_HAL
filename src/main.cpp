#include "stm32f1xx_hal.h"
#include "Led.hpp"
#include "TIM.hpp"
#include "ButtonInterupt.hpp"
volatile uint32_t flag = 0;
volatile uint32_t counter = 0;
TIM_HandleTypeDef htim2;
volatile uint32_t timer_flag = 0;

Button button(GPIOA, GPIO_PIN_0);
    Led led1(GPIOA, GPIO_PIN_1);     
    Led led9(GPIOA, GPIO_PIN_9);  
    Led blueLed(GPIOC, GPIO_PIN_13); 
TIM timer2(TIM2, htim2);
void MS_Init_Timer(void)
{

}
int main(void) {
    HAL_Init(); 
    timer2.Init();
    MS_Init_Timer();
    blueLed.Init();
    led1.Init();
    led9.Init();
    button.init();
    
    while(1) 
    {   
        if(timer_flag)
        {
            timer_flag = 0;
            led1.toggle();
            led9.toggle(); 
            blueLed.toggle();
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

extern "C" void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&htim2);
}

extern "C" void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) 
{
    counter += 10;
    if(htim->Instance == TIM2) 
    {
        timer_flag = 1;
    }
}


