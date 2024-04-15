/*#include"Snake.h"
#include <windows.h>

void clearConsole() {
	system("cls"); // 或者使用system("clear"); 在Unix/Linux系统中
}

int main() {
	Snake s(RIGHT);
	s.AddNode(9, 11);//尾	定义链表头节点为蛇头
	s.AddNode(9, 10);
	s.AddNode(10, 10);
	s.AddNode(11, 10);
	s.AddNode(12, 10);
	s.AddNode(13, 10);//头	链表尾节点为蛇尾
	int i = 0;
	while (1) {
		cout <<"Lenth: " << s.getLenth() << endl;
		s.PrintPositon();
		s.ShowSnakeInMap();
		Sleep(500);
		clearConsole();
		s.Move();
		++i;
		if (i >= 10) {
			s.ChangeOrientation(DOWN);//测试调整方向功能
		}
	}
	return 0;
}*/