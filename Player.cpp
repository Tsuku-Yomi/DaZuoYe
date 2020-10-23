#include "Player.h"
#include "enemy.h"
#include <cmath>
#include <cstdio>



extern std::list<Bullte_Base*> Bullte_List;
extern std::list<Enemy_Base*> Enemy_List;

void Player::Body_When_Tick()
{
	Show_HP();
	if (kbhit())
	{
		char a;
		a = getch();
		if (a==' '&&Cold_Time==0)
		{
			Shot();
			Cold_Time = 1;
		}
		if (Cold_Time != 0)
		{
			--Cold_Time;
			putimage(
				Body.Enity_Coord.x,
				0,
				8,
				Body.Enity_Coord.y,
				Img_Resource::Img_Save[12],
				0,
				0,
				8,
				8
			);
		}
	}
	ege::mousepos(&GamePad.x, &GamePad.y);
	Body.Enity_Speed.x = min(MaxSpeed, abs(GamePad.x - Body.Enity_Coord.x));
	if (GamePad.x - Body.Enity_Coord.x < 0)
	{
		Body.Enity_Speed.x *= -1;
	}
	Body.Enity_Speed.y = min(MaxSpeed, abs(GamePad.y - Body.Enity_Coord.y));
	if (GamePad.y - Body.Enity_Coord.y < 0)
	{
		Body.Enity_Speed.y *= -1;
	}
	Screen_Coord L=Body.Enity_Coord;
	Body.Enity_Coord.x += Body.Enity_Speed.x;
	Body.Enity_Coord.y += Body.Enity_Speed.y;
	if (Body.Enity_Coord.x < 0)
	{
		Body.Enity_Coord.x = 0;
	}
	if (Body.Enity_Coord.x > 608)
	{
		Body.Enity_Coord.x = 608;
	}
	if (Body.Enity_Coord.y < 0)
	{
		Body.Enity_Coord.y = 0;
	}
	if (Body.Enity_Coord.y > 986)
	{
		Body.Enity_Coord.y = 986;
	}
	if (Inv_Time > 0)
	{
		Inv_Time--;
	}
	else
	{
		auto Bullte_Iter = Bullte_List.begin();
		for (;Bullte_Iter != Bullte_List.end();)
		{
			if (FastTouchTest(L,Body.Enity_Coord,(*Bullte_Iter)->Body.Enity_Coord))
			{
				delete (*Bullte_Iter);
				Bullte_Iter = Bullte_List.erase(Bullte_Iter);
				Body.Health_Point--;
				Inv_Time = 20;
				break;
			}
			else
			{
				++Bullte_Iter;
			}
		}
	}
	/*testline*/
	//printf_s("%lf %lf\n", Body.Enity_Coord.x, Body.Enity_Coord.y);
	//end testline
	/*
	这里之后可以加一个东西
	当speed.x>特定值,putimage的图片参数用左倾的图片
	右倾同理
	*/
	putimage_transparent(
		NULL,
		Body.Enity_Img_ptr,
		Body.Enity_Coord.x-48,
		Body.Enity_Coord.y-48,
		0x0ed145
	);
}

bool Player::GameOver()
{
	if (Player_Life != 0 || Body.Health_Point != 0)
	{
		return true;
	}
	return false;
}

void Player::Show_HP()
{
	char Out[30];
	sprintf_s(Out, "Left Life:%d", Body.Health_Point);
	outtext(Out);
}

const int ShotJD = 64;

void Player::Shot()
{
	auto Enemy_Iter = Enemy_List.begin();
	for (;Enemy_Iter != Enemy_List.end();)
	{
		if ((*Enemy_Iter)->Body.Enity_Coord.x>=Body.Enity_Coord.x-16-ShotJD
			&& (*Enemy_Iter)->Body.Enity_Coord.x<=Body.Enity_Coord.x-16+ShotJD)
		{
			if ((*Enemy_Iter)->Body.Health_Point <= 0)
			{
				delete (*Enemy_Iter);
				Enemy_Iter = Enemy_List.erase(Enemy_Iter);
			}
			else
			{
				--(*Enemy_Iter)->Body.Health_Point;
				++Enemy_Iter;
			}
			
		}
		else
		{
			++Enemy_Iter;
		}
	}
}

Player::Player():Body(1, 3, Screen_Coord(320, 100))
{
	Player_Life = 0;
	Inv_Time = 100;
}