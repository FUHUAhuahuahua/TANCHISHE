#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include<assert.h>
#include<list>
#define ROW 30//行
#define COL 80//列
enum { UP, DOWN, LEFT, RIGHT };
using namespace std;
class Object {
public:
	void AddNode(int x, int y);//添加物品的像素点坐标（保证连续）
protected:
	vector<list<int>>m_Position;
	int m_Length;
};
