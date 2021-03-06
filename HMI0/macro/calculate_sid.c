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
typedef struct
{
    unsigned short flag;
    char device_name[32 + 1];
    char product_key[20 + 1];
    char device_secret[64 + 1];
    char device_id[64 + 1];
} iotx_device_info_t;


int MacroEntry()
{
	char SID_Buf[202] = {0};
	char Cache;
	iotx_device_info_t *SID;
	int i;
   ReadLocal("LW", 1400, 100, (void*)SID_Buf, 0);
	//ReadLocal("4X", 400, 100, (void*)SID_Buf, 0);
	for(i = 0;i < 100;i++)
	{
		Cache = SID_Buf[2 * i];
		SID_Buf[2 * i] = SID_Buf[2 * i + 1];
		SID_Buf[2 * i + 1] = Cache;
	}
  SID = (iotx_device_info_t *)SID_Buf;
	WriteLocal("LW", 400, 16, (void*)(SID->device_name), 0);
	WriteLocal("LW", 417, 10, (void*)(SID->product_key), 0);
	WriteLocal("LW", 428, 32, (void*)(SID->device_secret), 0);
	WriteLocal("LW", 461, 32, (void*)(SID->device_id), 0);
	
	return 0;
}
 