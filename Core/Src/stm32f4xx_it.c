/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "chassis.hpp"
#include "motor.hpp"
#include <stdio.h>
#include <string.h>
#include "flag.hpp"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
int currenttime=0;
unsigned int counterrecord[200];
unsigned int i=0;
extern uint8_t* pwmdata;
unsigned int counteri;
extern Chassis chassis;
extern flag flagset;
/* USER CODE END TD */

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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */
		currenttime++;
    if(currenttime%(1000/motor::Contect_frequency)==0){
      flagset.speedtestflag=1;
    }
    if(currenttime%10==0){
      flagset.motoroutflag=1;
    }
    if(currenttime==5000){
      flagset.test2=1;
    }
    if(currenttime==15000){
      flagset.test3=1;
    }
		if(currenttime==30000){
			currenttime=0;
		}
		HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */
  //�???10ms触发�???次中�???,�???测电机�?�度
   //   chassis.do_motor_speed();
  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */




  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE) && __HAL_UART_GET_IT_SOURCE(&huart1, UART_IT_IDLE)) // 确认产生了串口空闲中�??
{
    __HAL_UART_CLEAR_IDLEFLAG(&huart1); // 清除空闲中断标志
    HAL_UART_AbortReceive_IT(&huart1); // 终止中断式接�??
		//__HAL_UART_CLEAR_FLAG(&huart1, UART_FLAG_FE);//清除错误标志�??
	  //HAL_UART_Receive(&huart1, (uint8_t*)data, 10, 100);
		flagset.counterflag=1;
}
  /* USER CODE END USART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */
//中断处理函数，当�?????测到来自电机编码器a相触发的中断时，根据b相的电压判断电机正反�?????
//并更新对应电机的counter
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case GPIO_PIN_0:
		{
        chassis.motora.Motor_Counter();
		}break;
    case GPIO_PIN_9:
    {
        chassis.motorb.Motor_Counter();
    }break;
    case GPIO_PIN_2:
    {
        chassis.motorc.Motor_Counter();
    }
    case GPIO_PIN_4:
    {
        chassis.motord.Motor_Counter();
    }break;
	}
}
/*void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim){
/*
  if(htim==&htim3)//�????10ms触发�????次中�????,�????测电机�?�度
  {
      chassis.do_motor_speed();
  }
	if(htim==&htim2){
		currenttime++;
		if(currenttime%100==0){
			uint8_t test[10]="test1";
			HAL_UART_Transmit(&huart1, test, 5,0); // 发鿁test
		}
		if(currenttime==3000)
			chassis.do_motor_output(10000,0,0,0);
		if(currenttime==13000)
			chassis.do_motor_output(0,0,0,0);
		if(currenttime==16000)
			chassis.do_motor_output(10000,0,0,0);
		if(currenttime==26000)
			chassis.do_motor_output(0,0,0,0);
		if(currenttime==30000){
			currenttime=0;
		}
	}
  if(htim==&htim4)
  {
    float speed=chassis.return_speed();
    char speeddata[10];
    sprintf(speeddata, "%.2f", speed);

    // 计算字符串的长度
    int length = strlen(speeddata);

    // �???查数组是否有足够的空间来容纳换行�???
    if (length < sizeof(speeddata) - 1) {
        // 添加换行符到字符串末�???
        speeddata[length] = '\n';
        speeddata[length + 1] = '\0'; // 确保字符串以 null 终止
    }

const std::uint8_t *data = reinterpret_cast<const std::uint8_t *>(speeddata);
uint8_t test1[10]="test1";
HAL_UART_Transmit(&huart1, test1, 5, 500); 
HAL_UART_Transmit(&huart1, data, length + 1, 500); // 发�?�整个字符串，包括换行符
uint8_t test2[10]="test2";
HAL_UART_Transmit(&huart1, test2, 5, 500); 

  }
*/
//}
/*void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart==&huart1)//因为回调函数被各个串口共用，�??以要先判断是哪个串口�??
	{

	}
}*/
/* USER CODE END 1 */
