

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_


                           /* Macros for SSD decoder Pins Configurations */
						   
#define SSD_ENABLE_PORT			        MDIO_enuPORTB
#define SSD_K1_ENABLE_PIN			    MDIO_enuPIN1
#define SSD_K2_ENABLE_PIN			    MDIO_enuPIN2


#define SSD_DATA_PORT				    MDIO_enuPORTA


/* Options FOR SSD Type:
1- SSD_COM_CATHODE
2- SSD_COM_ANNODE
*/

#define SSD_TYPE                        SSD_COM_CATHODE
#endif /* SSD_CONFIG_H_ */
