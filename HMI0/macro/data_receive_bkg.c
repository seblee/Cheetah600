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
	/************��ȡalarm״̬��LW�Ĵ���******************/
	WriteLocal("LW", 1717, 14, (void*)&u16Alarm_status[0], 0);
	/************��ʾ���Ѹ���******************/
	Notifiction_red_count = Cache_status_ComSta_Alarm_critical_cnt;
	Notifiction_yellow_count = Cache_status_ComSta_Alarm_major_cnt;
	Notifiction_blue_count = Cache_status_ComSta_Alarm_mioor_cnt;

	if (Notifiction_red_count > 0)
		Notifiction_red = 1;
	else
		Notifiction_red = 0;

	if (Notifiction_yellow_count > 0)
		Notifiction_yellow = 1;
	else
		Notifiction_yellow = 0;

    if (Notifiction_blue_count > 0)
		Notifiction_blue = 1;
    else
		Notifiction_blue = 0;


	return 0;
}
 