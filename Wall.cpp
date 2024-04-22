#include"Wall.h"
Wall::Wall(int Color, int Orientation, int Length, int beginx, int beginy) {
	m_Color = Color;
	deque<int>x;
	deque<int>y;
	if (Orientation == UP) {
		assert(beginy - Length >= 0);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx);
			y.push_back(beginy - i);
		}
	}
	else if (Orientation == DOWN) {
		assert(beginy + Length < ROW);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx);
			y.push_back(beginy + i);
		}
	}
	else if (Orientation == RIGHT) {
		assert(beginx + Length < COL);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx + i);
			y.push_back(beginy);
		}
	}
	else if (Orientation == LEFT) {
		assert(beginx - Length >= 0);
		for (int i = 0; i < Length; ++i) {
			x.push_back(beginx - i);
			y.push_back(beginy);
		}
	}
	m_Position.push_back(x);
	m_Position.push_back(y);
	m_Length = Length;
}

int Wall::getColor() {
	return this->m_Color;
}

bool Wall::BeHit(Snake& s) {
	pair<int, int> sp = s.getPositon(0);
	for (int i = 0; i < this->m_Length; ++i) {
		pair<int, int> wp = this->getPositon(i);
		if (wp == sp) {
			return true;
		}
	}
	return false;
}



