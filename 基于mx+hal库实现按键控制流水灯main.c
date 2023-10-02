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
	int r=1,g=0;
	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
	
	
	while (1)
  { 
    
		if(keyflag==0)
		{
		if(r==1)
		{
			HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,GPIO_PIN_RESET);
		}
		else
		{
			HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,GPIO_PIN_SET);
		}
		if(g==1)
		{
		HAL_GPIO_WritePin(green_GPIO_Port,green_Pin,GPIO_PIN_RESET);
		}
		else
		{
			HAL_GPIO_WritePin(green_GPIO_Port,green_Pin,GPIO_PIN_SET);
		}
		}
	
		
		switch(keyflag)
		{
			case 1:
			{					
				HAL_GPIO_TogglePin(red_GPIO_Port,red_Pin);
				HAL_GPIO_TogglePin(green_GPIO_Port,green_Pin);	
				HAL_Delay(1000);
				
				
				if(HAL_GPIO_ReadPin(red_GPIO_Port,red_Pin)==GPIO_PIN_RESET)
				{
				r=1;
				}
				else
					r=0;
				
				if(HAL_GPIO_ReadPin(green_GPIO_Port,green_Pin)==GPIO_PIN_RESET)
				{
				g=1;
				}
				else
					g=0;
				break;
			}
			case 2:
			{
				HAL_GPIO_WritePin(red_GPIO_Port,red_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(green_GPIO_Port,green_Pin,GPIO_PIN_SET);
				break;
			}
	
		}
	}	
}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
	{
	
		if(GPIO_Pin==key1_Pin)
		{		 
			for(int i;i<1000;i++);
			if(HAL_GPIO_ReadPin(key1_GPIO_Port,key1_Pin)==GPIO_PIN_RESET)
			{
				keyflag++;
				
				while(HAL_GPIO_ReadPin(key1_GPIO_Port,key1_Pin)==GPIO_PIN_RESET);
				if(keyflag==3)
				{
					keyflag=0;
				}
				}
		}
	}
	
