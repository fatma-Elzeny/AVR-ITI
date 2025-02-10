

#ifndef HAL_KPD_INC_KPD_INTERFACE_H_
#define HAL_KPD_INC_KPD_INTERFACE_H_


#define KPD_NOT_PRESSED			0xFF

                       /*************** APIS PROTO TYPES ***************/

void KPD_voidInit    (void);
void KPD_voidGetValue(u8* copy_pu8ReturnedValue);


#endif /* HAL_KPD_INC_KPD_INTERFACE_H_ */
