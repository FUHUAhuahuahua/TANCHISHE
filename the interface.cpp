#include"Snake.h"
#include <graphics.h>		
#include <conio.h>
#define CELL_SIZE 20
#define Snake_Body_Size 10
int main() {
	Snake snake(RIGHT);
	snake.AddNode(9, 11);//β	��������ͷ�ڵ�Ϊ��ͷ
	snake.AddNode(9, 10);
	snake.AddNode(10, 10);
	snake.AddNode(11, 10);
	snake.AddNode(12, 10);
	snake.AddNode(13, 10);
	snake.AddNode(14, 10);
	snake.AddNode(15, 10);
	snake.AddNode(16, 10);
	snake.AddNode(17, 10);//ͷ	����β�ڵ�Ϊ��β
	int i = 0;

	initgraph(800, 600);//���ڴ�С
	setbkcolor(WHITE);//��Ϸ����ɫ
	
	while (true) {
		cout << "Lenth: " << snake.getLenth() << endl;
		Sleep(500);
		cleardevice();
		snake.Move();
		++i;
		if (i >= 10) {
			snake.ChangeOrientation(DOWN);//���Ե���������
		}
		cleardevice();//������
		snake.Move();
		//�˴�Ҫ�õ�itx��ity��position��
		setfillcolor(GREEN);//������ɫ��ĿǰΪ��ɫΪ��
		for (int i=0;i<snake.getLenth()  ; i++) {//��������Բ
			pair<int, int>p;
			p = snake.getPositon(i);

			fillcircle(p.first * CELL_SIZE + CELL_SIZE / 2,p.second * CELL_SIZE + CELL_SIZE / 2, Snake_Body_Size);
		}
		//setfillcolor(WHITE);//����������ɫ
		//int EYE_SIZE = Snake_Body_Size / 5;
		//fillcircle()//�۾������ͷ��λ���Լ���С;



	}
	closegraph();

}



