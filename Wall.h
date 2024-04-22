#pragma once
#include"Object.h"
#include"Snake.h"
class Wall : public Object{
public:
	Wall(int Color, int Orientation, int Length, int x, int y);
	bool BeHit(Snake& s);//如果被被蛇头撞上返回true	否则返回false
	int getColor();
private:
	int m_Color;
};
