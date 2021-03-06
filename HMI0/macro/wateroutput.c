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
	if(KeyWaterOutMode == 0)
	{
		if(waterOutKey)
		{
			ComPara_Water_Mode = 1;
			ComPara_Water_Flow = 5000;		
		}
		else
		{
			ComPara_Water_Mode = 0;
			ComPara_Water_Flow = 0;
		}		
	}else if(KeyWaterOutMode == 1)
	{
		if(KeyWateroutRestainCount>=2)
		{			
			ComPara_Water_Mode = 1;
			ComPara_Water_Flow = 5000;		
		}	else	
		{			
			ComPara_Water_Mode = 0;
			ComPara_Water_Flow = 0;
		} 
	}
waterOutKey2=0;
	return 0;
}
 