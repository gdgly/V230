#include	"STOPSYS.h"
#include "../../head_extern.h"
#include	"../led/led.h"
#include	"../motor/motor.h"
extern void data_init(void);
void stopsys_init(void)
{
	$ PADIER 0x68; //   pa5  pa3 pa6����������

}

void stopsys_even(void)
{
	if(sleep_time>500 )
	{
		motor_init();
		led_init();
		CLKMD.En_WatchDog = 0; // �رտ��Ź�ʱ��
		CLKMD = 0b_111_1_0_1_0_0; // 0xF4 ϵͳʱ�Ӵ�IHRC ��ΪILRC
		CLKMD.4 = 0; // IHRC ����  //ILRC=55khz
		while(1)
		{	
			if(pa.5==1 || pa.3==0 )
			{
				break;
			}
			STOPSYS; 	
		}
		CLKMD = 0x3c; // ϵͳʱ�Ӵ�ILRC ��ΪIHRC/8
		nop;
		data_init();	
	}
}