#pragma once
#ifndef _BASE_STAND
#define _BASE_STAND
#include <cmath>
#include <list>

const int n = 16;

//不需要重构

struct Screen_Coord//坐标传递结构
{
	double x, y;
	Screen_Coord(double _x=0, double _y=0)
	{
		x = _x;
		y = _y;
	}
};

struct Speed//同时存储Rod的类型id和图形ID
{
	double dx, dy;//加速度
	double x=0, y=0;//速度
	int TypeID, ImgID;
	int Tim;
	Speed(double _dx=0, double _dy=0,int _Tim=1,int _TypeID=1,int _ImgID=1):TypeID(_TypeID),ImgID(_ImgID)
	{
		dx = _dx;
		dy = _dy;
		if (_Tim <= 0)
		{
			_Tim = 1;
		}
		Tim = _Tim;
	}
	void Initial_Spd(double _x = 0, double _y = 0)//设定初速度
	{
		x = _x;
		y = _y;
	}
	void TickAdd()
	{
		x += dx;
		y += dy;
	}
};

bool FastTouchTest(const Screen_Coord& A, const Screen_Coord& B, const Screen_Coord& C);

/*
速度工作
1.每60帧视作一秒，速度为1单位/移动时间的值，每帧移动一次，虽然中间不做显示，但是会进行计算。
2.实体的碰撞，因为只要对玩家进行计算即可，所以每帧总是先计算玩家的移动，再计算玩家的碰撞，最后计算弹幕与敌人的移动。
碰撞计算：设帧初始地址为Ax,Ay,末地址为Bx,By;当弹幕的坐标Cx Cy满足 Ax>Cx>Bx时
如果Cy满足 Cy=(Cx-Ax)*(Ax-Bx)/(Ay-By)+Ay+-n(n为精确度）即视为碰撞
*/



#endif // !_BASE_STAND
