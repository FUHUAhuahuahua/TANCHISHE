#pragma once
#include"Object.h"
using namespace std;
class Snake : public Object{
public:
	void ShowSnakeInMap();//�Ե�ͼ����ʽ��ӡ���ߵ�λ��
	int getLenth();//��ȡ�ߵĳ���
	void PrintPositon();//��������ʽ��ӡ�ߵ�λ��
	void Move();//�ƶ�һ����λ
	void ChangeOrientation(int orientation);//�ı���ǰ������
	bool SnakeOccupied(int x, int y);//����xy���꣬�жϸ������Ƿ�����ռ�ã����򷵻�true�����򷵻�false
	pair<int, int> getPositon(int x);
	Snake(int orientation);
private:
	void DeleteBackNode();//ɾ���ߵ����һ���ڵ�
	int m_Orientation;
};