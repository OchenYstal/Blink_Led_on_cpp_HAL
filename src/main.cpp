#include "stm32f1xx_hal.h"
#include "Led.hpp"
#include "Button.hpp"
#define LED_GPIO_PORT_B GPIOB
#define LED_GPIO_PORT_A GPIOA

#define LED_PIN_2 GPIO_PIN_2
#define LED_PIN_1 GPIO_PIN_1
#define LED_PIN_9 GPIO_PIN_9
//Pin/Port Button
#define KEY_PIN GPIO_PIN_0


int main(void)
{
    HAL_Init();

    //Initialize button
    Button button(GPIOA, KEY_PIN);
    button.init();
    //Initialize led's
    Led led1(LED_GPIO_PORT_A, LED_PIN_1);
    Led led9(LED_GPIO_PORT_A, LED_PIN_9);
    Led led2(LED_GPIO_PORT_B, LED_PIN_2);
    led2.Init();
    led1.Init();
    led9.Init();
    //Main loop
    while(1)
    {
        if(button.isPressed())
        {
        led2.toggle();
        led1.toggle();
        led9.toggle();
        HAL_Delay(200);
        }
                
    }
}


extern "C"
{
    //Setting SysTick for HAL_Delay()
    void SysTick_Handler(void)
    {
        HAL_GetTick();
        HAL_IncTick();
    }
    void EXTI0_IRQHandler(void)
    {
        HAL_GPIO_EXTI_IRQHandler(KEY_PIN);
    }

}
