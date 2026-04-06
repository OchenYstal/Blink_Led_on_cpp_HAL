#include "stm32f1xx_hal.h"
#include "Led.hpp"

#define LED_GPIO_PORT_B GPIOB
#define LED_GPIO_PORT_A GPIOA

#define LED_PIN_2 GPIO_PIN_2
#define LED_PIN_1 GPIO_PIN_1
#define LED_PIN_9 GPIO_PIN_9
void SystemClock_Config(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    Led led1(LED_GPIO_PORT_A, LED_PIN_1);
    Led led9(LED_GPIO_PORT_A, LED_PIN_9);
    Led led2(LED_GPIO_PORT_B, LED_PIN_2);
    led2.Init();
    led1.Init();
    led9.Init();

    while(1)
    {
        led2.toggle();
        led1.toggle();
        led9.toggle();
        HAL_Delay(400);
    }
}


extern "C"
{
    void SysTick_Handler(void)
    {
        HAL_GetTick();
        HAL_IncTick();
    }

}
void Error_Handler(void)
{
    while(1)
    {
    }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  }
