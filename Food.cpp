#include"Food.h"
Food::Food(int size,int color,int posx,int posy) {
	deque<int>x;
	deque<int>y;
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

int Food::getColor() {
	return this->m_Color;
}

int Food::getSize() {
	return this->m_Size;
}

bool Food::BeHit(Snake& s) {
	pair<int, int> sp = s.getPositon(0);
	for (int i = 0; i < this->m_Length; ++i) {
		pair<int, int> wp = this->getPositon(i);
		if (wp == sp) {
			return true;
		}
	}
	return false;
}
