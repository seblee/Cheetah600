#include "macrotypedef.h"
#include "math.h"
#include "time.h"
#define version_1 1
#define version_2 0
#define version_3 28

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
/**********disable OperationComplete notifiction*****************/
	En_OperationComplete = 1;
/****************event********************************/
	event_category_min = 0;
	event_category_max = 255;
/****************version*****************************/
	Version_HMI_1 = version_1;
	Version_HMI_2 = version_2;
	Version_HMI_3 = version_3;
	
	Version_MCU_1 = 1;
	Version_MCU_2 = 0;
	Version_MCU_3 = 0;

	waterOutKey2 = 0;
   waterOutFlashFalg = 0;
	beepEnableSys = beepEnable;
	return 0;
}
 