#include"Object.h"
void Object::AddNode(int x, int y) {//һ��x��Ӧһ��y
	assert(x >= 0 && x < COL);
	assert(y >= 0 && y < ROW);
	m_Position[0].push_front(x);
	m_Position[1].push_front(y);
	++m_Length;
}