#include "macrotypedef.h"
#include "math.h"

/*
	Read,Write Local address function:
  	int ReadLocal( const char *type, int addr, int nRegs, void *buf, int flag  );
	int WriteLocal( const char *type, int addr, int nRegs, void *buf , int flag );

	Parameter:     type     is the string of "LW","LB" etc;
								address is the Operation address ;
 								nRegs    is the length of read or write ;
								buf        is the buffer which store the reading or writing data;
 								flag       is 0,then codetype is BIN,is 1  then codetype is BCD;
	return value : 1  ,Operation success
 								0,  Operation fail.

 	eg: read the value of local lw200 and write it to the lw202,with the codetype BIN,
		The code is :

    	short buf[2] = {0};
		ReadLocal("LW", 200, 2, (void*)buf, 0);
		WriteLocal("LW", 202, 2, (void*)buf, 0);
*/
int MacroEntry()
{
	MCU_Do = pre_units_state;

	mcu_ao_fan1 = pre_ao_fan1;
	mcu_ao_fan2 = pre_ao_fan2;
	mcu_ao_compressor1 = pre_ao_compressor1;
	mcu_ao_compressor2 = pre_ao_compressor2;
	mcu_ao_pump = pre_ao_pump;

	Compressor_EEV0_u16ManualPos = Compressor_EEV0_u16ManualPos_state;
	Compressor_EEV1_u16ManualPos = Compressor_EEV1_u16ManualPos_state;
	Compressor_EEV2_u16ManualPos = Compressor_EEV2_u16ManualPos_state;
	Compressor_EEV3_u16ManualPos = Compressor_EEV3_u16ManualPos_state;



	return 0;
}
 