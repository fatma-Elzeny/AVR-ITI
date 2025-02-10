

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/* Macros For Rs configuration */
#define LCD_RS_PORT			MDIO_enuPORTB
#define LCD_RS_PIN          MDIO_enuPIN1

/* Macros For RW configuration */
#define LCD_RW_PORT			MDIO_enuPORTB
#define LCD_RW_PIN          MDIO_enuPIN2

/* Macros For Enable configuration */
#define LCD_E_PORT			MDIO_enuPORTB
#define LCD_E_PIN           MDIO_enuPIN3

/* 4 Bit Mode Data Pins Configurtion */
#define LCD_D4_PORT			MDIO_enuPORTA
#define LCD_D4_PIN          MDIO_enuPIN4

#define LCD_D5_PORT			MDIO_enuPORTA
#define LCD_D5_PIN          MDIO_enuPIN5

#define LCD_D6_PORT			MDIO_enuPORTA
#define LCD_D6_PIN          MDIO_enuPIN6

#define LCD_D7_PORT			MDIO_enuPORTA
#define LCD_D7_PIN          MDIO_enuPIN7

#endif /* LCD_CONFIG_H_ */
