#pragma once
#ifndef _PLAYER_
#define _PLAYER_

#include "Rod.h"
#include "EnityBody.h"
#include "Bullte.h"
#include <graphics.h>

//���ﲻ�ܵ��ع���Ӱ��

class Player 
{
private:
	EnityBody Body;
	int Player_Life;//�л�����
					//�趨һ��Ϊÿ����n�л��ظ�һ��������Ӧ��Ϊ5��
	int Inv_Time;//�����к���޵�ʱ��,һ֡Ϊһ��λ
	int Cold_Time=0;//��������ȴʱ��
	mouse_msg GamePad;//���������Ϣ�����Բ���
	const double MaxSpeed = 30;//����ٶ�(���޸ģ������ÿ������ϵÿ֡�ƶ�30����
public:
	void Body_When_Tick();//��ײ����ҲҪ�ŵ�������ȥ���
	bool GameOver();
	void Show_HP();
	bool Is_Inv();
	void Shot();
	Player();
};


#endif