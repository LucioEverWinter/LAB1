/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG(int num);
void display7SEG0(int num);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int count = 0;
  while (1)
  {
	  count++;
	  	  	  if(count <= 5){
	  	  		  display7SEG(5-count);
	  	  		  HAL_GPIO_WritePin ( LED_RED_1_GPIO_Port , LED_RED_1_Pin , GPIO_PIN_RESET ) ;
				  HAL_GPIO_WritePin ( LED_YELLOW_1_GPIO_Port , LED_YELLOW_1_Pin , GPIO_PIN_SET ) ;
				  HAL_GPIO_WritePin ( LED_GREEN_1_GPIO_Port , LED_GREEN_1_Pin , GPIO_PIN_SET ) ;
	  	  		  if(count <= 2){
	  	  			  display7SEG0(2-count);
	  				HAL_GPIO_WritePin ( LED_RED_2_GPIO_Port , LED_RED_2_Pin , GPIO_PIN_SET ) ;
	  				HAL_GPIO_WritePin ( LED_YELLOW_2_GPIO_Port , LED_YELLOW_2_Pin , GPIO_PIN_SET ) ;
	  				HAL_GPIO_WritePin ( LED_GREEN_2_GPIO_Port , LED_GREEN_2_Pin , GPIO_PIN_RESET ) ;
	  	  		  }
	  	  		  else{
	  	  			  display7SEG0(5-count);
	  	  			HAL_GPIO_WritePin ( LED_RED_2_GPIO_Port , LED_RED_2_Pin , GPIO_PIN_SET ) ;
	  	  							HAL_GPIO_WritePin ( LED_YELLOW_2_GPIO_Port , LED_YELLOW_2_Pin , GPIO_PIN_RESET ) ;
	  	  							HAL_GPIO_WritePin ( LED_GREEN_2_GPIO_Port , LED_GREEN_2_Pin , GPIO_PIN_SET ) ;
	  	  		  }
	  	  	  }
	  	  	  else if(count <= 7){
	  	  		  display7SEG(7-count);
	  			HAL_GPIO_WritePin ( LED_RED_1_GPIO_Port , LED_RED_1_Pin , GPIO_PIN_SET ) ;
	  			  HAL_GPIO_WritePin ( LED_YELLOW_1_GPIO_Port , LED_YELLOW_1_Pin , GPIO_PIN_SET ) ;
	  			  HAL_GPIO_WritePin ( LED_GREEN_1_GPIO_Port , LED_GREEN_1_Pin , GPIO_PIN_RESET ) ;

	  	  		  display7SEG0(10-count);
				  HAL_GPIO_WritePin ( LED_RED_2_GPIO_Port , LED_RED_2_Pin , GPIO_PIN_RESET ) ;
				  HAL_GPIO_WritePin ( LED_YELLOW_2_GPIO_Port , LED_YELLOW_2_Pin , GPIO_PIN_SET ) ;
				  HAL_GPIO_WritePin ( LED_GREEN_2_GPIO_Port , LED_GREEN_2_Pin , GPIO_PIN_SET ) ;
	  	  	  }
	  	  	  else if(count <= 10){
	  	  		  display7SEG(10-count);
	  			HAL_GPIO_WritePin ( LED_RED_1_GPIO_Port , LED_RED_1_Pin , GPIO_PIN_SET ) ;
	  			HAL_GPIO_WritePin ( LED_YELLOW_1_GPIO_Port , LED_YELLOW_1_Pin , GPIO_PIN_RESET ) ;
	  			HAL_GPIO_WritePin ( LED_GREEN_1_GPIO_Port , LED_GREEN_1_Pin , GPIO_PIN_SET ) ;
	  	  		  display7SEG0(10-count);
	  	  	  }
	  	  	  if(count >= 10) count = 0;

	  	  	  HAL_Delay (1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin|LED_RED_1_Pin
                          |LED_YELLOW_1_Pin|LED_GREEN_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|D0_Pin
                          |E0_Pin|F0_Pin|G0_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|A0_Pin
                          |B0_Pin|C0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_2_Pin LED_YELLOW_2_Pin LED_GREEN_2_Pin LED_RED_1_Pin
                           LED_YELLOW_1_Pin LED_GREEN_1_Pin */
  GPIO_InitStruct.Pin = LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin|LED_RED_1_Pin
                          |LED_YELLOW_1_Pin|LED_GREEN_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin D0_Pin
                           E0_Pin F0_Pin G0_Pin D_Pin
                           E_Pin F_Pin G_Pin A0_Pin
                           B0_Pin C0_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|D0_Pin
                          |E0_Pin|F0_Pin|G0_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|A0_Pin
                          |B0_Pin|C0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void display7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
		break;
	case 1:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
		break;
	case 2:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 3:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 4:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 5:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 6:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 7:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
		break;
	case 8:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 9:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	default:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;

	}
}
void display7SEG0(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_SET ) ;
		break;
	case 1:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_SET ) ;
		break;
	case 2:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 3:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 4:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 5:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 6:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 7:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_SET ) ;
		break;
	case 8:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 9:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	default:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;

	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
