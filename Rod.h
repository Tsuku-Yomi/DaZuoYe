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
//成了，现在我都看不懂我在干嘛了
class EnityAI//作为弹幕AI时，Rod代表发射方向
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


