

#ifndef HAL_KPD_INC_KPD_CONFIG_H_
#define HAL_KPD_INC_KPD_CONFIG_H_

                        /* MACROS FOR KPD ROWS/COLS PORTS & PINS CONFIGURATION */
		 
// Input   
#define KPD_ROW0_PORT			MDIO_enuPORTC
#define KPD_ROW0_PIN 			MDIO_enuPIN3

#define KPD_ROW1_PORT			MDIO_enuPORTC
#define KPD_ROW1_PIN 			MDIO_enuPIN4

#define KPD_ROW2_PORT			MDIO_enuPORTC
#define KPD_ROW2_PIN 			MDIO_enuPIN5

#define KPD_ROW3_PORT			MDIO_enuPORTC
#define KPD_ROW3_PIN 			MDIO_enuPIN6


//Output
#define KPD_COL0_PORT			MDIO_enuPORTB
#define KPD_COL0_PIN 			MDIO_enuPIN4
			
#define KPD_COL1_PORT			MDIO_enuPORTB
#define KPD_COL1_PIN 			MDIO_enuPIN5
			
#define KPD_COL2_PORT			MDIO_enuPORTB
#define KPD_COL2_PIN 			MDIO_enuPIN6
			
#define KPD_COL3_PORT			MDIO_enuPORTB
#define KPD_COL3_PIN 			MDIO_enuPIN7


#define KPD_KEYS			    {{'1','2','3','A'},\
                                 {'4','5','6','B'},\
								 {'7','8','9','C'},\
								 {'*','0','#','D'}}


#endif /* HAL_KPD_INC_KPD_CONFIG_H_ */
