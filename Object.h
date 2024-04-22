#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include<assert.h>
#include<deque>
#define ROW 30//行
#define COL 40//列
#define LIGHTPURPLE RGB(176,164,227)
#define MIDDLEPURPLE RGB(164,171,214)
#define CELL_SIZE 20
#define Snake_Body_Size 10
enum { UP, DOWN, LEFT, RIGHT };
using namespace std;
class Object {
public:
	pair<int, int> getPositon(int x);
	int getLength();
protected:
	void AddNode(int x, int y);//添加物品的像素点坐标（保证连续）
	vector<deque<int>>m_Position;
	int m_Length;
};
