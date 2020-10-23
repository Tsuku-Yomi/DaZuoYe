#include "Bullte.h"

int  Bullte_Base::Now_Have_Bullte=0;

extern std::list<Bullte_Base*> Bullte_List;


Bullte_Base::~Bullte_Base()
{
	++Now_Have_Bullte;
}

void Bullte_Base::SpBullte_Tick()
{
	
}

bool Bullte_Base::Bullte_When_Tick()
{
	if (Body.Enity_Speed.Tim != 0)
	{
		--Body.Enity_Speed.Tim;
	}
	else
	{
		AI.Next_Spd(Body.Enity_Speed);
	}
	Body.Enity_Coord.x += Body.Enity_Speed.x;
	Body.Enity_Coord.y += Body.Enity_Speed.y;
	Body.Enity_Speed.TickAdd();
	this->SpBullte_Tick();
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
	////////////////
	putimage(
		Body.Enity_Coord.x-4,
		Body.Enity_Coord.y-4,
		Body.Enity_Img_ptr
	);
	return true;
}

Bullte_Base::Bullte_Base(std::vector<Speed>& In, Screen_Coord& Start_Coord,short ImgID)
	:AI(In),Body(ImgID,1,Start_Coord)
{
	++Now_Have_Bullte;
	Bullte_Damage = 1;
	//Bullte_List.insert(Bullte_List.end(), this);
}

Bullte_Base::Bullte_Base(Speed In, Screen_Coord& Start_Coord, short ImgID):AI(In),Body(ImgID,1,Start_Coord)
{
	++Now_Have_Bullte;
	Bullte_Damage = 1;
}

Bullte_Base* Bullte_Base::RtnBullte_Base(std::vector<Speed>& In, Screen_Coord& Start_Coord, short ImgID=11)
{
	return new Bullte_Base(In,Start_Coord,ImgID);
}

Bullte_Boom::Bullte_Boom(std::vector<Speed>& In, Screen_Coord& Start_Coord, int _BoomTime, short ImgID) 
:Bullte_Base(In,Start_Coord,ImgID)
{
	BoomTime = _BoomTime;
}

void Bullte_Boom::SpBullte_Tick()
{
	if (BoomTime != 0)
	{
		--BoomTime;
	}
	else
	{
		Bullte_List.insert(Bullte_List.begin(), new Bullte_Base(Speed(0.05, 0.1,10000),Body.Enity_Coord,11));
		Bullte_List.insert(Bullte_List.begin(), new Bullte_Base(Speed(-0.05, 0.1, 10000), Body.Enity_Coord, 11));
		--BoomTime;
	}
}
