#pragma once
#include "Base_Stand.h"
#include <vector>

#ifndef _ROD
#define _ROD
/*
·������ô�����ģ�
ÿ������·���ķ����ʵ�壨��Ļ���й֣���������趨��ʽ�����趨·��
·����Ψһָ��ʵ������ٶȵ���Ϣ��
·����������ʵ��ļ��ٶȲ��ٸı䣬���ᰴ���趨�켣һֱ�˶�ֱ�����⹹
*/
//���ˣ������Ҷ����������ڸ�����
class EnityAI//��Ϊ��ĻAIʱ��Rod�����䷽��
{
public:
	std::vector<Speed> Spd;
	void Next_Spd(Speed& In);
	int Spd_Iter;
	int Type;
	int Img_Type;
	//~EnityAI();
	EnityAI(
		std::vector<Speed>& In,
		int _Type = 0,
		int _Img_Type = 0
	);
	EnityAI(
		Speed& In,
		int _Type = 0,
		int _Img_Type = 0
	);
	enum
	{
		Base_Blt = 0 , Boom_Blt = 1
	};
	enum
	{
		Base_Emy = 0, Flash_Emy = 1
	};
	enum
	{
		Simple_Buttle_Img = 11,
		Player_Img = 1,
		Player_Bullte_Img = 12,
		Simple_Enemy_Img = 13,
		Boss_Img = 14
	};
};


#endif // !_ROD


