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

EnityAI::EnityAI(std::vector<Speed>& In):Spd(In),Spd_Iter(0)
{
}

EnityAI::EnityAI(Speed& In) : Spd_Iter(0), Spd()
{
	Spd.push_back(Speed());
	Spd.push_back(In);
}
