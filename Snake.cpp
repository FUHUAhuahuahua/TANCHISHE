#include "Snake.h"
void Snake::DeleteBackNode() {
	m_Position[0].pop_back();
	m_Position[1].pop_back();
	--m_Length;
}
Snake::Snake(int orientation) {
	m_Length = 0;
	list<int>x;
	list<int>y;
	m_Position.push_back(x);
	m_Position.push_back(y);




	m_Orientation = orientation;
}
int Snake::getLenth() {
	return m_Length;
}
void Snake::PrintPositon() {
	list<int>::const_iterator itx = m_Position[0].begin();
	list<int>::const_iterator ity = m_Position[1].begin();
	for (;itx != m_Position[0].end() && ity != m_Position[1].end(); itx++, ity++)//遍历坐标	打印坐标
		cout << *itx << "," << *ity << endl;
}
void Snake::Move() {
	DeleteBackNode();
	switch (m_Orientation)
	{
	case UP:
		AddNode(*(m_Position[0].begin()), *(m_Position[1].begin()) - 1);
		break;
	case DOWN:
		AddNode(*(m_Position[0].begin()), *(m_Position[1].begin()) + 1);
		break;
	case LEFT:
		AddNode(*(m_Position[0].begin()) - 1, *(m_Position[1].begin()));
		break;
	case RIGHT:
		AddNode(*(m_Position[0].begin()) + 1, *(m_Position[1].begin()));
		break;
	}
}
void Snake::ChangeOrientation(int orientation) {
	switch (orientation) {
	case UP:case DOWN:case LEFT:case RIGHT:
		m_Orientation = orientation;
		break;
	default:
		assert(orientation <= RIGHT && orientation >= UP);
		break;
	}
}
void Snake::ShowSnakeInMap() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (SnakeOccupied(j, i)) {
				cout << "#";
			}
			else {
				cout << "-";
			}
		}
		cout  << i << endl;
	}
}
bool Snake::SnakeOccupied(int x, int y) {
	list<int>::const_iterator itx = m_Position[0].begin();
	list<int>::const_iterator ity = m_Position[1].begin();
	for (; itx != m_Position[0].end() && ity != m_Position[1].end(); itx++, ity++) {
		if (x == *itx && y == *ity) {
			return true;
		}
	}
	return false;
}
pair<int, int> Snake::getPositon(int x) {
	list<int>::const_iterator itx = m_Position[0].begin();
	list<int>::const_iterator ity = m_Position[1].begin();
	for (int i = 0; i < x; i++) {
		itx++, ity++;
	}
	return pair<int,int>(*itx,*ity);
}