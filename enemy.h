#pragma once
#ifndef _ENEMY_
#define _ENEMY_

#include "Rod.h"
#include "EnityBody.h"
#include "Bullte.h"


class Enemy_Base
{
public:
	EnityBody Body;
	EnityAI Move_AI;
	std::vector<EnityAI> Bullte_AI;
	std::vector<EnityAI>::iterator Bullte_Iter;
	std::vector<int> BullteShotTime;//存储射击间隔，第一栏存储长期的射击间隔。
	std::vector<int>::iterator ShotTime_Iter;
	int ShotT,ShotTSave;
	virtual ~Enemy_Base();
	virtual bool Enemy_When_Tick();
	virtual void Spawn_Bullte();
	virtual void SpEnemy_Move();
	Enemy_Base(
		std::vector<Speed>& Move_In,
		std::vector< std::vector<Speed> >& Bullte_In,
		Screen_Coord Spawn_Coord,
		short ImgID,
		int HP,
		std::vector<int> &ShotTime
	);
	static Enemy_Base* SpwEnemy_Base(std::vector<Speed>&,
		std::vector< std::vector<Speed> >&,
		Screen_Coord,
		short,
		int,
		std::vector<int>&);
	//static Bullte_Base* (*FunPtr[10])(std::vector<Speed>&, Screen_Coord&, short);
};//已经改完了

/*class Enemy_Flash :public Enemy_Base
{
public:
	Enemy_Flash(
		std::vector<Speed>& Move_In,
		std::vector< std::vector<Speed> >& Bullte_In,
		Screen_Coord Spawn_Coord,
		short ImgID,
		int HP,
		int ShotTime,
		int _FlashTime
	);
	~Enemy_Flash();
	int FlashTime, FlashTimeSave;
	virtual void SpEnemy_Move();
	void Spawn_Bullte();
};*/
#endif