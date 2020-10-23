#include "enemy.h"

extern std::list<Enemy_Base*> Enemy_List;
extern std::list<Bullte_Base*> Bullte_List;


Bullte_Base* (*FunPtr[10])(std::vector<Speed>&, Screen_Coord&, short) = {Bullte_Base::RtnBullte_Base};

Enemy_Base::~Enemy_Base()
{
	
}

bool Enemy_Base::Enemy_When_Tick()
{
	if (Body.Enity_Speed.Tim != 0)
	{
		--Body.Enity_Speed.Tim;
	}
	else
	{
		Move_AI.Next_Spd(Body.Enity_Speed);
	}
	Body.Enity_Coord.x += Body.Enity_Speed.x;
	Body.Enity_Coord.y += Body.Enity_Speed.y;
	Body.Enity_Speed.TickAdd();
	this->SpEnemy_Move();
	if (Body.Enity_Coord.x < -100)
	{
		return false;
	}
	if (Body.Enity_Coord.x > 640)
	{
		return false;
	}
	if (Body.Enity_Coord.y > 1200)
	{
		return false;
	}
	if (Body.Enity_Coord.y < -100)
	{
		return false;
	}
	if (--ShotT == 0)
	{
		this->Spawn_Bullte();
	}
	////////////////
	putimage_transparent(
		NULL,
		Body.Enity_Img_ptr,
		Body.Enity_Coord.x - 54,
		Body.Enity_Coord.y - 54,
		0x0ed145
	);
	return true;
}

void Enemy_Base::Spawn_Bullte()//ÐÞ¸ÄÍê³É
{
	if (ShotTime_Iter != BullteShotTime.begin())//B
	{
		Bullte_List.insert(
				Bullte_List.begin(),
				FunPtr[(*Bullte_Iter).Type](
					(*Bullte_Iter).Spd,
					Body.Enity_Coord,
					11
				)
			);
	}
	++Bullte_Iter;
	++ShotTime_Iter;
	if (ShotTime_Iter == BullteShotTime.end())
	{
		ShotTime_Iter = BullteShotTime.begin();
	}
	ShotT = (*ShotTime_Iter);
	if (Bullte_Iter == Bullte_AI.end())
	{
		Bullte_Iter = Bullte_AI.begin();
	}
}

void Enemy_Base::SpEnemy_Move()
{

}

Enemy_Base::Enemy_Base(
	std::vector<Speed>& Move_In,
	std::vector< std::vector<Speed> >& Bullte_In,
	Screen_Coord Spawn_Coord,
	short ImgID,
	int HP,
	std::vector<int> &ShotTime
)
	:Body(ImgID,HP,Spawn_Coord),Move_AI(Move_In),ShotT((*ShotTime.begin()))
{
	for (auto SpdIter = Bullte_In.begin();SpdIter != Bullte_In.end();++SpdIter)
	{
		Bullte_AI.push_back(EnityAI((*SpdIter)));
	}
	BullteShotTime = ShotTime;
	ShotTime_Iter = BullteShotTime.begin();
	Bullte_Iter = Bullte_AI.begin();
	ShotTSave = ShotT;
	//Enemy_List.insert(Enemy_List.begin(), this);
}

Enemy_Base* Enemy_Base::SpwEnemy_Base(std::vector<Speed>& a, std::vector<std::vector<Speed>>& b, Screen_Coord c, short d, int e, std::vector<int>& f)
{
	return new Enemy_Base(a,b,c,d,e,f);
}

/*
Enemy_Flash::Enemy_Flash(
	std::vector<Speed>& Move_In,
	std::vector< std::vector<Speed> >& Bullte_In,
	Screen_Coord Spawn_Coord,
	short ImgID,
	int HP,
	int ShotTime,
	int _FlashTime
) :Enemy_Base(Move_In,
	Bullte_In,
	Spawn_Coord,
	ImgID,
	HP,
	ShotTime),
	FlashTime(_FlashTime), FlashTimeSave(_FlashTime)
{

}

Enemy_Flash::~Enemy_Flash()
{
	
}

void Enemy_Flash::SpEnemy_Move()
{
	
	if (FlashTime != 0)
	{
		--FlashTime;
	}
	else
	{
		Body.Enity_Coord.x = 640 - Body.Enity_Coord.x;
		FlashTime = FlashTimeSave;
	}
}

void Enemy_Flash::Spawn_Bullte()
{
	//Bullte_List.insert(Bullte_List.begin(), new Bullte_Boom(Bullte_AI.Spd, Body.Enity_Coord, 60));
}
*/