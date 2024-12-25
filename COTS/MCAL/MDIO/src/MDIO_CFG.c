/* MDIO_CFG.c
 *
 * Created: 12/24/2024 8:06:27 PM
 *  Author: Fatma Yosry Elzeny
 */ 
#include "MDIO_CFG.h"
#include "MDIO.h"

// array to return the configuration of the pins and set it during run time 

/* To set Your configuration You can choose 
    0 for output 
	1 for input pull up 
	2 for input 
*/
MDIO_enuConfiguration_t MDIO_enuArrPinConfig[NUM_OF_PORTS * NUM_OF_PINS] =
{
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};
