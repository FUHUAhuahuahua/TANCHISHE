#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include<assert.h>
#include<list>
#define ROW 30//��
#define COL 80//��
enum { UP, DOWN, LEFT, RIGHT };
using namespace std;
class Object {
public:
	void AddNode(int x, int y);//�����Ʒ�����ص����꣨��֤������
protected:
	vector<list<int>>m_Position;
	int m_Length;
};
