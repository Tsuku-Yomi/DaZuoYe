#include "Rod.h"

void EnityAI::Next_Spd(Speed& In)
{
	if (Spd_Iter != Spd.size())
	{
		In.dx = Spd[Spd_Iter].dx;
		In.dy = Spd[Spd_Iter].dy;
		In.Tim = Spd[Spd_Iter].Tim;
		++Spd_Iter;
	}
}

EnityAI::EnityAI(std::vector<Speed>& In,int _Type,int _Img_Type):Spd(In),Spd_Iter(0),Type(_Type),Img_Type(_Img_Type)
{
	
}

EnityAI::EnityAI(Speed& In, int _Type,int _Img_Type) :Spd_Iter(0), Spd(),Type(_Type),Img_Type(_Img_Type)
{
	Spd.push_back(Speed());
	Spd.push_back(In);
}
