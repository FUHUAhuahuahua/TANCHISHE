/*#include"Snake.h"
#include <windows.h>

void clearConsole() {
	system("cls"); // ����ʹ��system("clear"); ��Unix/Linuxϵͳ��
}

int main() {
	Snake s(RIGHT);
	s.AddNode(9, 11);//β	��������ͷ�ڵ�Ϊ��ͷ
	s.AddNode(9, 10);
	s.AddNode(10, 10);
	s.AddNode(11, 10);
	s.AddNode(12, 10);
	s.AddNode(13, 10);//ͷ	����β�ڵ�Ϊ��β
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
			s.ChangeOrientation(DOWN);//���Ե���������
		}
	}
	return 0;
}*/