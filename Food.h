#pragma once
#include"Object.h"
enum{SMALL,MIDDLE,BIG};
class Food :public Object {
public:
	Food(int size,int color, int posx, int posy);
private:
	int m_Color;
	int m_Size;
};