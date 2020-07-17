#pragma once
#ifndef _PLAYER_
#define _PLAYER_

#include "Rod.h"
#include "EnityBody.h"
#include "Bullte.h"
#include <graphics.h>

//这里不受到重构的影响

class Player 
{
private:
	EnityBody Body;
	int Player_Life;//残机数，
					//设定一下为每击落n敌机回复一个，上限应该为5个
	int Inv_Time;//被击中后的无敌时间,一帧为一单位
	int Cold_Time=0;//射击后的冷却时间
	mouse_msg GamePad;//鼠标输入消息，用以操纵
	const double MaxSpeed = 30;//最大速度(待修改），最快每个坐标系每帧移动30像素
public:
	void Body_When_Tick();//碰撞函数也要放到这里面去检测
	bool GameOver();
	void Show_HP();
	bool Is_Inv();
	void Shot();
	Player();
};


#endif