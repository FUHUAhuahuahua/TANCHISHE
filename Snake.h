#pragma once
#include"Object.h"
using namespace std;
class Snake : public Object{
public:
	Snake(int Orientation, int Length, int beginx, int beginy);
	void Move();//移动一个单位
	void ChangeOrientation(int orientation);//改变蛇前进朝向
	bool SnakeOccupied(int x, int y);//输入xy坐标，判断该坐标是否被蛇所占用，是则返回true，否则返回false
	void DrawSnake();
	bool BeHit(Snake& s);//如果被被蛇头撞上返回true	否则返回false
	static void DrawSnakeBody(int x,int y);
	//void ShowSnakeInMap();//以地图的形式打印出蛇的位置
	//void PrintPositon();//以坐标形式打印蛇的位置
private:
	void DeleteBackNode();//删除蛇的最后一个节点
	int m_Orientation;
};
