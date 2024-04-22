#include"Snake.h"
#include"Wall.h"
#include"Food.h"
#include<conio.h>
#include<graphics.h>
#include <windows.h>
using namespace std;

void clearConsole() {
	system("cls"); // 或者使用system("clear"); 在Unix/Linux系统中
}

void DrawBody(int x,int y) {
	fillcircle(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2, Snake_Body_Size);
}

int main() {
	Snake snake(DOWN, 15, 20, 10);
	Wall wall(RED, DOWN, 20, 0, 0);
	initgraph(800,600);//窗口大小
	setbkcolor(WHITE);//游戏背景色

	while (!wall.BeHit(snake) && !snake.BeHit(snake)) {
		cout << snake.getPositon(1).first << ", " << snake.getPositon(1).second << endl;
		//snake.ShowSnakeInMap();
		Sleep(200);
		cleardevice();
		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				snake.ChangeOrientation(LEFT);
				break;
			case 's':
				snake.ChangeOrientation(DOWN);
				break;
			case 'd':
				snake.ChangeOrientation(RIGHT);
				break;
			case 'w':
				snake.ChangeOrientation(UP);
				break;
			}
		}


		//snake.Move();
		cleardevice();//清理窗口
		snake.Move();
		snake.DrawSnake();
		//此处要得到itx，ity，position；



		setfillcolor(wall.getColor());//蛇身颜色（目前为绿色为）
		for (int i = 0; i < wall.getLength(); ++i) {
			pair<int, int>p;
			p = wall.getPositon(i);
			DrawBody(p.first, p.second);
		}
		//setfillcolor(WHITE);//设置蛇眼颜色
		//int EYE_SIZE = Snake_Body_Size / 5;
		//fillcircle()//眼睛相对于头的位置以及大小;



	}
	cout << "游戏结束" << endl;
	closegraph();

}

