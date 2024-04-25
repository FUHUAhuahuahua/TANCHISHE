#include <graphics.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>

#define MAXSTAR 200	// 星星总数

void Text_rule() {
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	int top = 80;
	char arr1[] = "^点击“PLAY”进入游戏。";
	outtextxy(100, top+30, arr1);
	char arr2[] = "^使用键盘中上下左右控制蛇的方向（双人模式下玩家2使用“W”，";
	outtextxy(100, top+30+30, arr2);
	char arr3[] = "“S”，“A”，“D”控制方向）。";
	outtextxy(100, top+30+30+30, arr3);
	char arr4[] = "^玩家通过控制蛇头吃到果实会增加蛇的长度，碰到炸弹则会结束游";
	outtextxy(100, top+30+30+30+30, arr4);
	char arr5[] = "戏，吃到？？则会进入一段时间无敌时刻，无敌时刻下无视伤害。";
	outtextxy(100, top+30+30+30+30+30, arr5);
	char arr6[] = "最终长度将计入得分。";
	outtextxy(100, top+30+30+30+30+30+30, arr6);
	char arr7[] = "^玩家可选择有墙和无墙两种模式。有墙模式下墙体视为有效伤害，";
	outtextxy(100, top+30+30+30+30+30+30+30, arr7);
	char arr8[] = "触碰则结束游戏；无墙模式下蛇穿过边缘可从另一边出现。";
	outtextxy(100, top+30+30+30+30+30+30+30+30, arr8);
	char arr9[] = "^祝您游戏愉快！！";
	outtextxy(100, top+30+30+30+30+30+30+30+30+30, arr9);	
	char arr_[] = "返回...";
	outtextxy(590, 450, arr_);
}

void Text_return() {
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr_[] = "返回...";
	outtextxy(590, 450, arr_);
}

void Cover(int left ,int top,int right,int bottom) {
	setfillcolor(BLACK);  // 设置填充颜色为黑色
	solidrectangle(left,top,right,bottom);
};
struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// 初始化星星
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// 移动星星
void MoveStar(int i)
{
	// 擦掉原来的星星
	putpixel((int)star[i].x, star[i].y, 0);

	// 计算新位置
	star[i].x += star[i].step;
	if (star[i].x > 640)	InitStar(i);

	// 画新星星
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

void Interface() {
	initgraph(648, 486);			// 创建绘图窗口
	IMAGE img_whole, img_start, img_rule, img_mode, img_choose, img_wall, img_NoWall, img;
	loadimage(&img_whole, "./总体.png", 648, 486);
	loadimage(&img_start, "./开始游戏.png", 648, 486);
	loadimage(&img_rule, "./游戏规则.png", 648, 486);
	loadimage(&img_mode, "./模式.png", 648, 486);
	loadimage(&img_wall, "./选择有墙.png", 648, 486);
	loadimage(&img_NoWall, "./选择无墙.png", 648, 486);
	loadimage(&img_choose, "./选择.png", 648, 486);
	loadimage(&img, "./开始.png", 108, 81);

	bool IsWall = true;
	bool IsStart = false;

Start:
	putimage(0, 0, &img_whole); // 放置“开始游戏”图标
	MOUSEMSG msg;
	while (true)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg) {
		case WM_LBUTTONDOWN:
			if (msg.x >= 250 && msg.x <= 397 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_start);
			}
			if (msg.x >= 433 && msg.x <= 482 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_rule);
			}
			if (msg.x >= 174 && msg.x <= 215 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_mode);
			}
			break;
		case WM_LBUTTONUP:
			if (msg.x >= 250 && msg.x <= 397 && msg.y >= 406 && msg.y <= 455) {
				Cover(0, 0, 648, 486);
				putimage(0, 0, &img);
				IsStart = true;
			}
			if (msg.x >= 433 && msg.x <= 482 && msg.y >= 406 && msg.y <= 455) {
				Cover(0, 0, 648, 486);
				Text_rule();
				//初始化所有星星
				for (int i = 0; i < MAXSTAR; i++)
				{
					InitStar(i);
					star[i].x = rand() % 640;
				}

				// 绘制星空，按任意键退出
				while (!_kbhit())
				{
					for (int i = 0; i < MAXSTAR; i++)
						MoveStar(i);
					Text_rule();
					Sleep(20);
					msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 593 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {
						goto Start;
					}
				}
			}
			if (msg.x >= 174 && msg.x <= 215 && msg.y >= 406 && msg.y <= 455) {
				putimage(0, 0, &img_choose); // 显示img_choose图片
				Text_return();
				while (true) {
					msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 184 && msg.x <= 483 && msg.y >= 218 && msg.y <= 258) {
						putimage(0, 0, &img_wall); // 显示img_wall图片
						Text_return();
						IsWall = true;
					}
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 184 && msg.x <= 483 && msg.y >= 272 && msg.y <= 317) {
						putimage(0, 0, &img_NoWall);
						Text_return();
						IsWall = false;
					}
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 593 && msg.x <= 648 && msg.y >= 446 && msg.y <= 472) {
						goto Start;
					}
				}
			}
			break;
		default:
			break;
		}
		if (IsStart == true) {
			break;
		}
	}
	getchar();
	closegraph();// 关闭绘图窗口
}

int main()
{
	srand((unsigned)time(NULL));	// 随机种子
	Interface();
	return 0;
}
