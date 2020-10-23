#include "Base_Stand.h"


bool FastTouchTest(
	const Screen_Coord& A, 
	const Screen_Coord& B,
	const Screen_Coord& C)
{
	if (A.x+n >= C.x && C.x+n >= B.x || A.x <= n+C.x && C.x <= n+B.x)
	{
		double F = (C.x - A.x+0.001) * (A.x - B.x+0.001) / (A.y - B.y+0.001) + A.y;
		if (C.y >= F - n && C.y <= F + n)
		{
			return true;
		}
	}
	return false;
}
