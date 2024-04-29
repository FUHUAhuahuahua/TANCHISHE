#include"Food.h"
Food::Food(int size, int color, int posx, int posy) {
	deque<int>x;
	deque<int>y;
	x.push_back(posx);
	y.push_back(posy);
	switch (size) {
	case MIDDLE:
		m_Size = MIDDLE;
		break;
	case BIG:
		m_Size = BIG;
		break;
	default:
		m_Size = SMALL;
		break;
	}
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Color = color;
	m_Length = 1;
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
void Food::DrawFood(int it_size) {
	int x, y;
	pair<int,int> p = this->getPositon(0);
	x = p.first;
	y = p.second;
	setfillcolor(this->m_Color);
	switch (this->m_Size) {
	case SMALL:
		solidcircle(x * CELL_SIZE + (CELL_SIZE / 2), y * CELL_SIZE + (CELL_SIZE / 2), it_size);
		break;
	case MIDDLE:
		solidcircle(x * CELL_SIZE + (CELL_SIZE / 2), y * CELL_SIZE + (CELL_SIZE / 2), it_size);
		break;
	case BIG:
		solidcircle(x * CELL_SIZE + (CELL_SIZE / 2), y * CELL_SIZE + (CELL_SIZE / 2), it_size);
		break;
	default:
		break;
	}
}
