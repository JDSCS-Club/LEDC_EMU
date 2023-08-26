/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : WWDG.c
    * @ProjectName          : SEPTA ML
    * @TargetDevices        : LEDC-A5.2
    * @ToolVersions         : IAR 8.32.2.
    * Dependencies          : SEPTA_ML_FDI.BIN
    * @Revision             : 1.0.0.0
    ******************************************************************************
    * @AdditionalComments   :
    *                        1) Ver 1.0.0.0 : 2018/07/11 First release.
    ******************************************************************************
*/


#include "stm32f4xx_hal.h"
#include "WWDG.h"
#include "main.h"

WWDG_HandleTypeDef   WwdgHandle;



/**
  * @brief WWDG MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable 
  * @param hwwdg: WWDG handle pointer
  * @retval None
  */
void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
	/* WWDG Peripheral clock enable */	
	if (hwwdg->Instance == WWDG)
	{

		  /* Peripheral clock enable */
		__HAL_RCC_WWDG_CLK_ENABLE();

		/* Peripheral interrupt init */
		HAL_NVIC_SetPriority(WWDG_IRQn, 0, 0); // ���ͷ�Ʈ�� Ȱ��ȭ �Ѵ�.
		HAL_NVIC_EnableIRQ(WWDG_IRQn);	// ���ͷ�Ʈ�� Ȱ��ȭ �Ѵ�.

	}
	
	
}
/*****************************************************************************
* @brief - �Լ� �ʱ�ȭ 
* @param -
* @retval-
******************************************************************************/
void WWDG_Init(void)
{
	
	/*##-1- Check if the system has resumed from WWDG reset ####################*/
	if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET) //Reset �� �⵿ �ߴ��� Ȯ�� �Ѵ�.
	{ 
		
		MyPrintf_USART1("**WWDG RESET** \n\r");
		/* Clear reset flags */
		__HAL_RCC_CLEAR_RESET_FLAGS();    
	}
	
	
	/*##-2- Configure the WWDG peripheral ######################################*/
  /* WWDG clock counter = (PCLK1 (42MHz)/4096)/8) = 1281 Hz (~780 us) 
     WWDG Window value = 80 means that the WWDG counter should be refreshed only 
     when the counter is below 80 (and greater than 64) otherwise a reset will 
     be generated. 
     WWDG Counter value = 127, WWDG timeout = ~780 us * 64 = 49.9 ms */
    
	WwdgHandle.Instance = WWDG;

	WwdgHandle.Init.Prescaler = WWDG_PRESCALER_8;
	WwdgHandle.Init.Window    = 80;
	WwdgHandle.Init.Counter   = 127;
	WwdgHandle.Init.EWIMode = WWDG_EWI_ENABLE;
	
	if (HAL_WWDG_Init(&WwdgHandle) != HAL_OK)
	{
		/* Initialization Error */
		
		MyPrintf_USART1("**WWDG Error** \n\r");
		
		WWDG_Error_Handler();
	}
	
	
	
}


/**
* @brief This function handles Window watchdog interrupt.
*/
void WWDG_IRQHandler(void)
{

	HAL_WWDG_IRQHandler(&WwdgHandle); 

}


/**
  * @brief  WWDG Early Wakeup callback.
  * @param  hwwdg  pointer to a WWDG_HandleTypeDef structure that contains
  *                the configuration information for the specified WWDG module.
  * @retval None
  */
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef* hwwdg)
{
	
	if (HAL_WWDG_Refresh(&WwdgHandle) != HAL_OK) //WWDG ī���Ͱ� 0x40���� 0x3F �� �ٿ��ϴ� ���� ȣ�� �ȴ�. ȣ��Ǹ� ī���͸� �����Ѵ�.
	{
		WWDG_Error_Handler();
	}
	
}


/*****************************************************************************
* @brief - Ÿ�̸� ���ͷ�Ʈ �Լ�
* @param -
* @retval-
******************************************************************************/

static void WWDG_Error_Handler(void)
{
	/* Turn LED5 on */
	while (1)
	{
	}
}







