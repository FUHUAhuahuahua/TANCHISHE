#include"Snake.h"
#include"Wall.h"
#include"Food.h"
#include<conio.h>
#include<graphics.h>
#include <windows.h>
using namespace std;

void DetectPress(Snake&snake) {
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
}


int main() {
	Snake snake(DOWN, 15, 20, 10);
	Wall wall(RED, DOWN, 20, 0, 0);
	Food food(SMALL, GREEN, 10, 10);
	initgraph(800,600);//窗口大小
	setbkcolor(WHITE);//游戏背景色
	while (1) {
		if (wall.BeHit(snake)) {
			cout << "撞墙" << endl;
			break;
		}
		if (snake.BeHit(snake)) {
			cout << "自身相撞" << endl;
			break;
		}
		cout << snake.getPositon(0).first << ", " << snake.getPositon(0).second << endl;
		Sleep(300);
		cleardevice();//清理窗口
		DetectPress(snake);
		snake.Move();
		snake.DrawSnake();
		wall.DrawWall();
	}
	cout << "游戏结束" << endl;
	closegraph();
	return 0;
}

