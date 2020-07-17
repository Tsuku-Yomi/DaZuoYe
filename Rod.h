#pragma once
#include "Base_Stand.h"
#include <vector>

#ifndef _ROD
#define _ROD
/*
路径是怎么工作的？
每个含有路径的非玩家实体（弹幕，敌怪）从起点以设定方式到达设定路径
路径是唯一指导实体产生速度的信息。
路径结束代表实体的加速度不再改变，即会按照设定轨迹一直运动直到被解构
*/

//这里全部都要重构

class EnityAI//作为弹幕AI时，Rod代表发射方向//能一类两用，太爽了
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


