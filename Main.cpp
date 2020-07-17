#include <graphics.h>
#include <Windows.h>
#include <iostream>
#include "Base_Stand.h"
#include "EnityBody.h"
#include "Bullte.h"
#include "enemy.h"
#include <fstream>
#include "Player.h"
#include "Rod.h"
#include <mmsystem.h>//PlaySound函数支持，用以播放游戏音乐
#include <list>
using namespace std;

extern std::list<Bullte_Base*> Bullte_List= std::list<Bullte_Base*>();
extern std::list<Enemy_Base*> Enemy_List=std::list<Enemy_Base*>();
/*
留给来花里胡哨的修改的人
这就是一坨电子垃圾
不要吐槽
你需要一个ege图形库作为前置（请百度
插入新图片请到Img_Resource类的ReadFile函数
修改机制请派生Enemy_Base类和Bullte_Base类
残余大量垃圾代码，请随意删除
大量功能未添加，请自行添加
大量代码无注释，请自己想象
作者：Tsuku_Yomi_
*/

Screen_Coord Using_To_Rod[100];
vector<Speed> Rod_For_Enemy[100];
vector<Speed> Rod_For_Bullte[100];


void ReadEnemyFile();

int main()
{
	initgraph(640, 1024);
	setcaption("STG Coder:YangHaiJun 8002119366 PE1912");
	//PlaySound(TEXT("1.wav"), NULL, SND_ASYNC);
	Img_Resource::ReadFile();
	Player NowPlayer=Player();
	vector<Speed> Enemy_Spd;
	vector<Speed> Bullte_Spd;
	////TestLine
	Enemy_Spd.push_back(Speed(0, 0, 1));
	Enemy_Spd.push_back(Speed(0, 0.01, 100));
	Enemy_Spd.push_back(Speed(0, 0, 300));
	Enemy_Spd.push_back(Speed(0, -0.01, 100));
	Enemy_Spd.push_back(Speed(0, 0, 300));
	Bullte_Spd.push_back(Speed(0, 0.1, 1000));
	char Test[1000];
	Enemy_List.insert(Enemy_List.begin(),new Enemy_Flash(Enemy_Spd, Bullte_Spd, Screen_Coord(100, 100), 1, 10, 110, 60));
	//////////////*/
	auto Bullte_Iter = Bullte_List.begin();
	auto Enemy_Iter = Enemy_List.begin();
	ReadEnemyFile();
	fstream EnemyLine;
	EnemyLine.open("EnemyLine.txt");
	int BS = 0;
	EnemyLine >> BS;
	for (;is_run()&&NowPlayer.GameOver();delay_fps(60))
	{
		cleardevice();
		putimage(0, 0, Img_Resource::Img_Save[321]);
		if (Enemy_List.empty())
		{
			if (BS != 0)
			{
				--BS;
				int TinLine,RodE,RodB,x,y,Img,HP,ShotT;
				EnemyLine >> TinLine;
				for (int i = 0;i < TinLine;i++)
				{
					EnemyLine >> RodE >> RodB >> x >> y >> Img >> HP >> ShotT;
					Enemy_List.insert(Enemy_List.begin(),new Enemy_Base(Rod_For_Enemy[RodE], Rod_For_Bullte[RodB], Screen_Coord(x, y), Img, HP, ShotT));
				}
			}
			else
			{
				break;
			}
		}
		NowPlayer.Body_When_Tick();
		Bullte_Iter = Bullte_List.begin();
		for (;Bullte_Iter != Bullte_List.end();)
		{
			if (!(*Bullte_Iter)->Bullte_When_Tick())
			{
				delete (*Bullte_Iter);
				Bullte_Iter=Bullte_List.erase(Bullte_Iter);
			}
			else
			{
				++Bullte_Iter;
			}
		}
		Enemy_Iter = Enemy_List.begin();
		for (;Enemy_Iter != Enemy_List.end();)
		{
			if (!(*Enemy_Iter)->Enemy_When_Tick())
			{
				delete* Enemy_Iter;
				getch();
				Enemy_Iter=Enemy_List.erase(Enemy_Iter);
			}
			else
			{
				++Enemy_Iter;
			}
		}
	}
	outtext("Game OVER,Press any key to exit");
	getch();
	ege::closegraph();
	return 0;
}

void ReadEnemyFile()
{
	fstream EnemyFile;
	EnemyFile.open("Enemy_Rod.txt");
	int Line,Lo;
	double dx, dy;
	int No, tim;
	EnemyFile >> Line;
	for (int i = 0;i < Line;i++)
	{
		EnemyFile >> No>>Lo;
		Rod_For_Enemy[No].push_back(Speed(0, 0, 1));
		for (int r = 0;r < Lo;r++)
		{
			EnemyFile >> dx >> dy >> tim;
			Rod_For_Enemy[No].push_back(Speed(dx, dy, tim));
		}
	}
	EnemyFile.close();
	EnemyFile.open("Bullte_Rod.txt");
	EnemyFile >> Line;
	for (int i = 0;i < Line;i++)
	{
		EnemyFile >> No >> Lo;
		Rod_For_Bullte[No].push_back(Speed(0, 0, 1));
		for (int r = 0;r < Lo;r++)
		{
			EnemyFile >> dx >> dy >> tim;
			Rod_For_Bullte[No].push_back(Speed(dx, dy, tim));
		}
	}
	EnemyFile.close();
}