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

//����ȫ����Ҫ�ع�

class EnityAI//��Ϊ��ĻAIʱ��Rod�����䷽��//��һ�����ã�̫ˬ��
{
public:
	std::vector<Speed> Spd;
	void Next_Spd(Speed& In);
	int Spd_Iter;
	//~EnityAI();
	EnityAI(
		std::vector<Speed>& In
	);
	EnityAI(
		Speed& In
	);
};


#endif // !_ROD


