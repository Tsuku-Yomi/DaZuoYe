#pragma once
#ifndef _ENITY_PYS
#define _ENITY_PYS
#include "Base_Stand.h"
#include <graphics.h>

//���ﲻ���ܵ��ع���Ӱ��

class EnityBody
{
public:
	Screen_Coord Enity_Coord;
	Speed Enity_Speed;
	PIMAGE Enity_Img_ptr;//�ⶫ����ָ��
	//Delʱ��Ҫdelimg,��Ϊ����Ǳ�������Դ�����
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





