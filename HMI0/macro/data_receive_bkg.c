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
	int i;
	/************读取alarm状态到LW寄存器******************/
	for(i = 0;i < 14;i++)
	{
		Cache_u16Alarm_status[i] = u16Alarm_status[i];
	}
	/************显示提醒个数******************/
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

	/************读取系统状态到状态寄存器*****************/
	for(i = 0;i < 5;i++)
	{
		Cache_ComSta_Status_remap[i] = ComSta_Status_remap[i];
	}
/**************读取温湿度******************************/
	Cache_status_ComSta_TH0_Temp = status_ComSta_TH0_Temp;
	Cache_status_ComSta_TH0_Hum = status_ComSta_TH0_Hum;
/**************读取水位 水量****************************/
	Cache_status_ComSta_Water_D_WL = status_ComSta_Water_D_WL;
	Cache_status_ComSta_Water_S_WL = status_ComSta_Water_S_WL;
	Cache_status_ComSta_Water_TotalWater = status_ComSta_Water_TotalWater;
	if((Cache_status_ComSta_Water_D_WL >= 0) &&
	(Cache_status_ComSta_Water_D_WL <= 1000))
	{
		Water_D_WL_Display = Cache_status_ComSta_Water_D_WL;
      Water_D_LEVEL_Display = Cache_status_ComSta_Water_D_WL/100;
      Water_D_WL_Display_gif = Water_D_LEVEL_Display * 2;
	}
	else 
	{
		Water_D_WL_Display = 0;
		Water_D_LEVEL_Display = 0;
      Water_D_WL_Display_gif = 0;

	}
/**************读取测试模式****************************/
	Cache_ComPara_Manual_Test_En = ComPara_Manual_Test_En;
/**************屏保配置****************************/
/****
 *5分钟
 *300秒
 **/
	if(Cache_ComPara_Manual_Test_En  != 0)
		ScreenSaver = WindowCurrent;
	else 
		ScreenSaver = 0;
/**************时间设置****************************/
	if(Cache_ComPara_Manual_Test_En  != 0)
		ScreenSaver = WindowCurrent;
	else 
		ScreenSaver = 0;


//模拟界面
/*
	Notifiction_red_count =0;
	Notifiction_yellow_count =1;
	Notifiction_blue_count = 0;

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
//**************读取温湿度*****************************
	Cache_status_ComSta_TH0_Temp = 250;
	Cache_status_ComSta_TH0_Hum = 750;
//*************读取水位 水量**************************
	Cache_status_ComSta_Water_D_WL = 850; 
	if((Cache_status_ComSta_Water_D_WL >= 0) &&
	(Cache_status_ComSta_Water_D_WL <= 1000))
	{
		Water_D_WL_Display = Cache_status_ComSta_Water_D_WL;
	}
	else 
	{
		Water_D_WL_Display = 0;
	}
Cache_ComSta_Status_remap[1]  = 0xff;
*/
	return 0;
}
 