#include "EnityBody.h"

const int BattleGroundX = 640;
const int BattleGroundY = 1024;
PIMAGE Img_Resource::Img_Save[400];

EnityBody::EnityBody(
	short ImgID,
	int _HP,
	Screen_Coord Spawn_Coord) :Health_Point(_HP), Enity_Speed()
{
	Enity_Img_ptr = Img_Resource::Img_Save[ImgID];
	Enity_Coord = Spawn_Coord;
	//Body_When_Spawn();
}

void Img_Resource::ReadFile()//要啥自己往里放，注意一下不要位置冲突了
{
	Img_Save[1] = newimage(32, 32);
	getimage(Img_Save[1], "Player.png", 0, 0);
	Img_Save[11] = newimage(8, 8);
	getimage(Img_Save[11], "Bullte.png", 0, 0);
	Img_Save[321] = newimage(640, 1024);
	getimage(Img_Save[321], "BackGround.png", 0, 0);
	Img_Save[12] = newimage(8, 8);
	getimage(Img_Save[12], "PlayerBullte.png", 0, 0);
}
