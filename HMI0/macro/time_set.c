#include "macrotypedef.h"
#include "math.h"
#include "time.h"

#define CPAD_CMD_SET_TIME 0x12

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
	time_t now;
	now =	time(0);
	now -= 28800;
	ob_data_reg_0 = (unsigned short)(now>>16);
	ob_data_reg_1 = (unsigned short)(now);
	ob_cmd_reg = CPAD_CMD_SET_TIME;
	return 0;
}
 