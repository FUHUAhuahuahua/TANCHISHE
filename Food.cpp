#include"Food.h"
Food::Food(int size,int color,int posx,int posy) {
	list<int>x;
	list<int>y;
	x.push_back(posx);
	y.push_back(posy);
	switch (size) {
	case MIDDLE:
		m_Size = 7;
		break;
	case BIG:
		m_Size = 10;
		break;
	default:
		m_Size = 5;
		break;
	}
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Color = color;
}