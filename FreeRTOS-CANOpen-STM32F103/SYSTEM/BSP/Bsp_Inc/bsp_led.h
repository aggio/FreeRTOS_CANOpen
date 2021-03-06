/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  Jim
  * @version V1.0
  * @date    01-Sep-2014
  * @brief   This is the led driver function.
  * @brief   ARM_BMS: 
	*										LED  	 PORT		ACTION 	
  *          					LED1 : PA0		Low-On, High-Off
  *          					LED2 : PA1		Low-On, High-Off
  *          					LED3 : PA2		Low-On, High-Off
	* 			   ARM_LIFTER: 
	*										LED  	 PORT		ACTION 	
  *          					GREEN: PA0		Low-On, High-Off
  *          					RED  : PA1		Low-On, High-Off
  *          					BLUE : PA2		Low-On, High-Off
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 CSST Robot Research Center</center></h2>
  *
  ******************************************************************************
  */
 

#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "bsp.h"

#ifdef ARM_BMS
	/* BMS control borad */
	#define RCC_LED RCC_APB2Periph_GPIOA
	#define LEDPORT GPIOA
	#define LED1    GPIO_Pin_0
	#define LED2    GPIO_Pin_1
	#define LED3    GPIO_Pin_2
#endif

#ifdef ARM_LIFTER
	/* Lifter control board */
	#define RCC_LED 	RCC_APB2Periph_GPIOA
	#define LEDPORT   GPIOB
	#define LED1 			GPIO_Pin_5
	#define LED2   		GPIO_Pin_6
	#define LED3  		GPIO_Pin_7
	#define LED_GREEN LED1
	#define LED_RED   LED2
	#define LED_BLUE  LED3
	#define GREEN_ON	bsp_LedOn(1)
	#define RED_ON		bsp_LedOn(2)
	#define BLUE_ON		bsp_LedOn(3)
	#define GREEN_OFF	bsp_LedOff(1)
	#define RED_OFF		bsp_LedOff(2)
	#define BLUE_OFF	bsp_LedOff(3)
	#define GREEN_Toggle	bsp_LedToggle(1,100)
	#define RED_Toggle		bsp_LedToggle(2,100)
	#define BLUE_Toggle		bsp_LedToggle(3,100)
#endif

void bsp_InitLed(void);
extern void bsp_LedOn(uint8_t _no);
extern void bsp_LedOff(uint8_t _no);
extern void bsp_LedToggle(uint8_t _no, uint32_t _us);
uint8_t bsp_IsLedOn(uint8_t _no);

#endif

/****************** (C) COPYRIGHT CSST Robot Research Center *****END OF FILE****/
