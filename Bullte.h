#pragma once
#ifndef _BULLTE_
#define _BULLTE_

#include "Rod.h"
#include "EnityBody.h"
#include <vector>


class Bullte_Base
{
public:
	EnityAI AI;
	EnityBody Body;
	int Bullte_Damage;
	bool Bullte_When_Tick();
	virtual void SpBullte_Tick();
	virtual ~Bullte_Base();
	static int Now_Have_Bullte;//场上存在的弹幕数量
	Bullte_Base(
		std::vector<Speed> &In,
		Screen_Coord& Start_Coord,
		short ImgID=11
	);
	Bullte_Base(
		Speed In,
		Screen_Coord& Start_Coord,
		short ImgID = 11
	);
	static Bullte_Base* RtnBullte_Base(
		std::vector<Speed>&,
		Screen_Coord&,
		short
	);
};

class Bullte_Boom:public Bullte_Base
{
private:
	int BoomTime;
public:
	Bullte_Boom(
		std::vector<Speed>& In,
		Screen_Coord& Start_Coord,
		int _BoomTime,
		short ImgID = 11
	);
	void SpBullte_Tick();
};

#endif // !_BULLTE_