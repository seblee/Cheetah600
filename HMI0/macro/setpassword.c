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
//pass_reg[0]	������
//pass_reg[1]	������
//pass_reg[2]	ȷ������
 
int MacroEntry()
{
	int i;
	switch(pass_type)
	{
		case 0:	//user
			if(pass_reg[0] == lw_current_pass1)		//�жϵ�ǰ�����Ƿ���ȷ
			{
				if(pass_reg[1] == pass_reg[2])
				{
					//��������ɹ�
					lw_current_pass1 	= pass_reg[1];
					MessageChar = 0;
					MessageWindow = 1;
				}
				else
				{
					//�������벻ƥ��
					MessageChar = 2;
					MessageWindow = 1;
				}
			}
			else
			{
				//���벻��ȷ
				MessageChar = 1;
				MessageWindow = 1;
			}
		break;

		case 1:	//service
			if(pass_reg[0] == lw_current_pass2)		//�жϵ�ǰ�����Ƿ���ȷ
			{
				if(pass_reg[1] == pass_reg[2])
				{
					//��������ɹ�
					lw_current_pass2 	= pass_reg[1];
					MessageChar = 0;
					MessageWindow = 1;
				}
				else
				{
					//�������벻ƥ��
					MessageChar = 2;
					MessageWindow = 1;
				}
			}
			else
			{
				//���벻��ȷ
				MessageChar = 1;
				MessageWindow = 1;
			}
		break;

		case 2:	//factory
			if(pass_reg[0] == lw_current_pass3)		//�жϵ�ǰ�����Ƿ���ȷ
			{
				if(pass_reg[1] == pass_reg[2])
				{
					//��������ɹ�
					lw_current_pass3 	= pass_reg[1];
					MessageChar = 0;
					MessageWindow = 1;
				}
				else
				{
					//�������벻ƥ��
					MessageChar = 2;
					MessageWindow = 1;
				}
			}
			else
			{
				//���벻��ȷ
				MessageChar = 1;
				MessageWindow = 1;
			}
		break;

		default:

		break;
	}
	return 0;
}

 