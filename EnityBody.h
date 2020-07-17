#pragma once
#ifndef _ENITY_PYS
#define _ENITY_PYS
#include "Base_Stand.h"
#include <graphics.h>

//这里不会受到重构的影响

class EnityBody
{
public:
	Screen_Coord Enity_Coord;
	Speed Enity_Speed;
	PIMAGE Enity_Img_ptr;//这东西是指针
	//Del时不要delimg,因为这个是保存在资源库里的
	int Health_Point;
	EnityBody(short ImgID,int _HP, Screen_Coord Spawn_Coord);
	virtual ~EnityBody() {};
};

class Img_Resource
{
public:
	static PIMAGE Img_Save[400];
	friend class EnityBody;
	static void ReadFile();
};

#endif // !_ENITY_PYS





