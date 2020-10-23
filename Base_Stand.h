#pragma once
#ifndef _BASE_STAND
#define _BASE_STAND
#include <cmath>
#include <list>

const int n = 16;

//����Ҫ�ع�

struct Screen_Coord//���괫�ݽṹ
{
	double x, y;
	Screen_Coord(double _x=0, double _y=0)
	{
		x = _x;
		y = _y;
	}
};

struct Speed//ͬʱ�洢Rod������id��ͼ��ID
{
	double dx, dy;//���ٶ�
	double x=0, y=0;//�ٶ�
	int TypeID, ImgID;
	int Tim;
	Speed(double _dx=0, double _dy=0,int _Tim=1,int _TypeID=1,int _ImgID=1):TypeID(_TypeID),ImgID(_ImgID)
	{
		dx = _dx;
		dy = _dy;
		if (_Tim <= 0)
		{
			_Tim = 1;
		}
		Tim = _Tim;
	}
	void Initial_Spd(double _x = 0, double _y = 0)//�趨���ٶ�
	{
		x = _x;
		y = _y;
	}
	void TickAdd()
	{
		x += dx;
		y += dy;
	}
};

bool FastTouchTest(const Screen_Coord& A, const Screen_Coord& B, const Screen_Coord& C);

/*
�ٶȹ���
1.ÿ60֡����һ�룬�ٶ�Ϊ1��λ/�ƶ�ʱ���ֵ��ÿ֡�ƶ�һ�Σ���Ȼ�м䲻����ʾ�����ǻ���м��㡣
2.ʵ�����ײ����ΪֻҪ����ҽ��м��㼴�ɣ�����ÿ֡�����ȼ�����ҵ��ƶ����ټ�����ҵ���ײ�������㵯Ļ����˵��ƶ���
��ײ���㣺��֡��ʼ��ַΪAx,Ay,ĩ��ַΪBx,By;����Ļ������Cx Cy���� Ax>Cx>Bxʱ
���Cy���� Cy=(Cx-Ax)*(Ax-Bx)/(Ay-By)+Ay+-n(nΪ��ȷ�ȣ�����Ϊ��ײ
*/



#endif // !_BASE_STAND
