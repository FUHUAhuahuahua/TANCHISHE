#include"Snake.h"
#include <graphics.h>		
#include <conio.h>
#define CELL_SIZE 20
#define Snake_Body_Size 10
int main() {
	Snake snake(RIGHT);
	snake.AddNode(9, 11);//尾	定义链表头节点为蛇头
	snake.AddNode(9, 10);
	snake.AddNode(10, 10);
	snake.AddNode(11, 10);
	snake.AddNode(12, 10);
	snake.AddNode(13, 10);
	snake.AddNode(14, 10);
	snake.AddNode(15, 10);
	snake.AddNode(16, 10);
	snake.AddNode(17, 10);//头	链表尾节点为蛇尾
	int i = 0;

	initgraph(800, 600);//窗口大小
	setbkcolor(WHITE);//游戏背景色
	
	while (true) {
		cout << "Lenth: " << snake.getLenth() << endl;
		Sleep(500);
		cleardevice();
		snake.Move();
		++i;
		if (i >= 10) {
			snake.ChangeOrientation(DOWN);//测试调整方向功能
		}
		cleardevice();//清理窗口
		snake.Move();
		//此处要得到itx，ity，position；
		setfillcolor(GREEN);//蛇身颜色（目前为绿色为）
		for (int i=0;i<snake.getLenth()  ; i++) {//遍历蛇身花圆
			pair<int, int>p;
			p = snake.getPositon(i);

			fillcircle(p.first * CELL_SIZE + CELL_SIZE / 2,p.second * CELL_SIZE + CELL_SIZE / 2, Snake_Body_Size);
		}
		//setfillcolor(WHITE);//设置蛇眼颜色
		//int EYE_SIZE = Snake_Body_Size / 5;
		//fillcircle()//眼睛相对于头的位置以及大小;



	}
	closegraph();

}



