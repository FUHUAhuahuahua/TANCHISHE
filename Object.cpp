#include"Object.h"
void Object::AddNode(int x, int y) {//Ò»¸öx¶ÔÓ¦Ò»¸öy
	assert(x >= 0 && x < COL);
	assert(y >= 0 && y < ROW);
	m_Position[0].push_front(x);
	m_Position[1].push_front(y);
	++m_Length;#include"Object.h"
void Object::AddNode(int x, int y) {//一个x对应一个y
	assert(x >= 0 && x < COL);
	assert(y >= 0 && y < ROW);
	m_Position[0].push_front(x);
	m_Position[1].push_front(y);
	++m_Length;
}

pair<int, int> Object::getPositon(int x) {
	list<int>::const_iterator itx = m_Position[0].begin();
	list<int>::const_iterator ity = m_Position[1].begin();
	for (int i = 0; i < x; i++) {
		itx++, ity++;
	}
	return pair<int, int>(*itx, *ity);
}

int Object::getLength() {
	return this->m_Length;
}
}
