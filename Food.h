#pragma once
#include"Object.h"
#include"Snake.h"
enum { SMALL, MIDDLE, BIG };
class Food :public Object {
public:
	Food(int size, int color, int posx, int posy);
	bool BeHit(Snake& s);//如果被被蛇头撞上返回true	否则返回false
	int getColor();
	int getSize();
	void DrawFood(int it_size); // 绘制食物
private:
	int m_Color;
	int m_Size;
};
