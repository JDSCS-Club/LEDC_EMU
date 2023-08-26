

#include "stm32f4xx_hal.h"
#include "charLCD.h"
#include "main.h"




uint32_t mLcd_TimerCnt = 0;

char mLCDPrintBuf[4][20];


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/


void lcd_Main(void)
{ 
  
  if(mLcd_TimerCnt == 3000)
  { 
        //lcd_init();
        
  }
  
  if(mLcd_TimerCnt > 3500 && !(mLcd_TimerCnt%1000))
  {
    
    mLcd_TimerCnt++;
//        lcd_putstr(0,0,&mLCDPrintBuf[0][0]);
//        lcd_putstr(0,1,&mLCDPrintBuf[1][0]);
//        lcd_putstr(0,2,&mLCDPrintBuf[2][0]);
//        lcd_putstr(0,3,&mLCDPrintBuf[3][0]);
//        
    

    
    
  }
  
  
  
}
/*****************************************************************************
* @brief -  PB - GPIO_PIN_5     LCD-RS
*           PB - GPIO_PIN_6     LCD-RW
*           PB - GPIO_PIN_7     LCD-E
*           PE - GPIO_PIN_0     LCD-D0
*           PE - GPIO_PIN_1     LCD-D1 
*           PE - GPIO_PIN_2     LCD-D2 
*           PE - GPIO_PIN_3     LCD-D3 
*           PE - GPIO_PIN_4     LCD-D4 
*           PE - GPIO_PIN_5     LCD-D5 
*           PE - GPIO_PIN_6     LCD-D6
*           PE - GPIO_PIN_11    LCD-D7
* @param -
* @retval-
******************************************************************************/


void TextLCD_GPIO_Init(void)
{

    GPIO_InitTypeDef   GPIO_InitStructure;


    /* Enable GPIOx clock */
    __GPIOE_CLK_ENABLE();
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 ;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStructure); 
    
    
    __GPIOG_CLK_ENABLE();
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    GPIO_InitStructure.Pin = GPIO_PIN_5 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStructure); 
    
    
    __GPIOI_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Pin = GPIO_PIN_7;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStructure);
    

}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void lcd_init(void)
{

  HAL_GPIO_WritePin(GPIOI,GPIO_PIN_7, GPIO_PIN_RESET);
    /*****************************************/
//    	instruction_out(0x08); // ���÷��� ����
//    	HAL_Delay(2);
//    	instruction_out(0x38); // 8��Ʈ, �۲�
//    	HAL_Delay(2);
//        instruction_out(0x38); // 8��Ʈ, �۲�
//    	HAL_Delay(2);
//        
//    	instruction_out(0x06); // ��Ʈ�� ��尡 ���� �� ������� ����.
//        HAL_Delay(2);
//    	instruction_out(0x17); // ���� ��带 �����ϰ� ������ ��
//    	instruction_out(0x01); // ���÷��� �����
//    	//instruction_out(0x0C); // ���÷��� �ѱ�
//        instruction_out(0x0F); // ���÷��� �ѱ�

    /********************************************/
	
	instruction_out(0x13); // ���� ��带 �����ϰ� ���÷��� ������ OFF
	//HAL_Delay(1);
	instruction_out(0x17); // ���� ��带 �����ϰ� ���÷��� ������ ��
	
	//instruction_out(0x08); // ���÷��� ����
	
	
    //HAL_Delay(1);
    instruction_out(0x38); // 8��Ʈ, �۲� Function Set
	// HAL_Delay(1);
    instruction_out(0x38); // 8��Ʈ, �۲� Function Set
	// HAL_Delay(1);
	instruction_out(0x38); // 8��Ʈ, �۲� Function Set
    //HAL_Delay(2);
    //instruction_out(0x13); // ���� ��带 �����ϰ� ���÷��� ������ OFF
	// HAL_Delay(1);
	instruction_out(0x06); // ��Ʈ�� ���
	
	// HAL_Delay(1);
	instruction_out(0x02); //Retun home
   //HAL_Delay(1);
    instruction_out(0x17); // ���� ��带 �����ϰ� ���÷��� ������ ��
     //HAL_Delay(1);
	instruction_out(0x08); // ���÷��� ����
	//HAL_Delay(1);
	instruction_out(0x01); // ���÷��� �����
	//HAL_Delay(1);
    instruction_out(0x0F); // ���÷��� �ѱ�
	//HAL_Delay(1);
  
//    //HAL_Delay(2);
//    instruction_out(0x02); //Retun home
//    //HAL_Delay(2);
//    instruction_out(0x06); // ��Ʈ�� ���
//    //HAL_Delay(2);
//	
////	instruction_out(0x01); // ���÷��� �����
////	instruction_out(0x0F); // ���÷��� �ѱ�
//  
//	//instruction_out(0x06); // ��Ʈ�� ���
	

}



/*****************************************************************************
* @brief -  PB - GPIO_PIN_5     LCD-RS
*           PB - GPIO_PIN_6     LCD-RW
*           PB - GPIO_PIN_7     LCD-EN
*           PE - GPIO_PIN_0     LCD-D0
*           PE - GPIO_PIN_1     LCD-D1 
*           PE - GPIO_PIN_2     LCD-D2 
*           PE - GPIO_PIN_3     LCD-D3 
*           PE - GPIO_PIN_4     LCD-D4 
*           PE - GPIO_PIN_5     LCD-D5 
*           PE - GPIO_PIN_6     LCD-D6
*           PE - GPIO_PIN_11    LCD-D7
*
* @param -
* @retval-
******************************************************************************/
void instruction_out(unsigned char b)
{
	uint32_t i = 0;
	
	 //LCD ���� �ð� ���� �� �ʱ�ȭ �ϱ� ���� �߰� �ݵ�� �ʿ�.
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET); // D0
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET); // D1
    
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_RESET); // D2
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET); // D3
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, GPIO_PIN_RESET); // D4
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET); // D5
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET); // D6
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D7 


		
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); //RS Low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); //RS Low
	

			
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low
    
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);//EN High
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);//EN High
    

			
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, ((b & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D0
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, ((b & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D1
    
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, ((b & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D2
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, ((b & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D3
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, ((b & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D4
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, ((b & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D5
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, ((b & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D6
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, ((b & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D7

			
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); //RS Low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); //RS Low
	
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); //EN Low  
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); //EN Low 
		


    //LCD ���� �ð� ���� �� �ʱ�ȭ �ϱ� ���� �߰� �ݵ�� �ʿ�.
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET); // D0
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET); // D1
    
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_RESET); // D2
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET); // D3
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, GPIO_PIN_RESET); // D4
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET); // D5
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET); // D6
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D7    
    
    //HAL_Delay(1);
	
	for(i = 0;i<300;i++){};
	//for(i = 0;i<5000;i++){};
	
	//	HAL_Delay(1);

}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/


void display_out(unsigned char b)
{
	uint32_t i = 0;
    //LCD ���� �ð� ���� �� �ʱ�ȭ �ϱ� ���� �߰� �ݵ�� �ʿ�.
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET); // D0
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET); // D1
    
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_RESET); // D2
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET); // D3
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, GPIO_PIN_RESET); // D4
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET); // D5
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET); // D6
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D7   
	
     // �� ����.
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); //RS High
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); //RS High
		
	
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low


    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); //EN High
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET); //EN High

    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, ((b & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D0
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, ((b & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D1
    
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, ((b & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D2
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, ((b & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D3
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, ((b & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D4
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, ((b & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D5
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, ((b & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D6
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11,((b & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET)); // D7
	
		
        
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); //RS High
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); //RS High
	
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET); //RW Low

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); //EN Low 
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); //EN Low 
    
//	 //LCD ���� �ð� ���� �� �ʱ�ȭ �ϱ� ���� �߰� �ݵ�� �ʿ�.
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_RESET); // D0
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET); // D1
    
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_RESET); // D2
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET); // D3
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_8, GPIO_PIN_RESET); // D4
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET); // D5
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET); // D6
    
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET); // D7    
    
    //HAL_Delay(1);
	for(i = 0;i<200;i++){};
	//for(i = 0;i<5000;i++){};
	//	HAL_Delay(1);
	
    

}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void lcd_busuFlag(unsigned char b)
{

	GPIOB->ODR = GPIOE->ODR | 0x40; //PB6 - RW�� High
	GPIOB->ODR = GPIOE->ODR & ~0x80; //PB7 - EN�� Low
	
	GPIOB->ODR = GPIOE->ODR | 0x04; //PB7 - EN�� High

  	//���� 4��Ʈ


	GPIOB->ODR = GPIOE->ODR & ~0x80; //PB7 - EN�� Low
  

	GPIOB->ODR = GPIOE->ODR | 0x40; //PB6 - RW�� High



}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void lcd_gotoxy( char x,  char y)
{

    switch(y)
    {    
        case 0 : instruction_out(0x80+x); break;
        case 1 : instruction_out(0xC0+x); break;
        case 2 : instruction_out(0x94+x); break;
        case 3 : instruction_out(0xD4+x); break;
    }
}
/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

int s_lcd_putstr = 0;
void lcd_putstr( char x,  char y,  char *str)
{
    unsigned int i=0;
    
    HAL_GPIO_WritePin(GPIOI,GPIO_PIN_7, GPIO_PIN_RESET);
	
    
    lcd_gotoxy(x,y);
	
    do
    {
        display_out(str[i]&0xFF);
		
		
    }
    while(str[++i]!='\0');
	
	s_lcd_putstr++;
	
	
}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void lcd_Timer(void)
{
  mLcd_TimerCnt++;
  
  
  
  
  
}



















