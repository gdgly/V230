#include	"TIM16.h"

void T16_init(void)
{
	$  T16M     IHRC, /1, BIT11;    // T16 ����ʱ�� = 16MHz��
                                        // ����ʱ�� = 2^12 * 1uS /16 = 256 uS
	$ INTEN t16;	//�ж�Դ
	INTRQ = 0; 		// ���INTRQ
	DISGINT	 		// ����ȫ���ж�
	ENGINT 			// ����ȫ���ж�
}

