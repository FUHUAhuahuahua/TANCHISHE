#pragma once
#include"Object.h"
class Wall : public Object{
public:
	Wall(int Color, int Orientation, int Length, int x, int y);
private:
	int m_Color;
};
