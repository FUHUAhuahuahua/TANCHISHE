#include <graphics.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>

#define MAXSTAR 200	// ��������

void Text_rule() {
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	int top = 80;
	char arr1[] = "^�����PLAY��������Ϸ��";
	outtextxy(100, top+30, arr1);
	char arr2[] = "^ʹ�ü������������ҿ����ߵķ���˫��ģʽ�����2ʹ�á�W����";
	outtextxy(100, top+30+30, arr2);
	char arr3[] = "��S������A������D�����Ʒ��򣩡�";
	outtextxy(100, top+30+30+30, arr3);
	char arr4[] = "^���ͨ��������ͷ�Ե���ʵ�������ߵĳ��ȣ�����ը����������";
	outtextxy(100, top+30+30+30+30, arr4);
	char arr5[] = "Ϸ���Ե�����������һ��ʱ���޵�ʱ�̣��޵�ʱ���������˺���";
	outtextxy(100, top+30+30+30+30+30, arr5);
	char arr6[] = "���ճ��Ƚ�����÷֡�";
	outtextxy(100, top+30+30+30+30+30+30, arr6);
	char arr7[] = "^��ҿ�ѡ����ǽ����ǽ����ģʽ����ǽģʽ��ǽ����Ϊ��Ч�˺���";
	outtextxy(100, top+30+30+30+30+30+30+30, arr7);
	char arr8[] = "�����������Ϸ����ǽģʽ���ߴ�����Ե�ɴ���һ�߳��֡�";
	outtextxy(100, top+30+30+30+30+30+30+30+30, arr8);
	char arr9[] = "^ף����Ϸ��죡��";
	outtextxy(100, top+30+30+30+30+30+30+30+30+30, arr9);	
	char arr_[] = "����...";
	outtextxy(590, 450, arr_);
}

void Text_return() {
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	char arr_[] = "����...";
	outtextxy(590, 450, arr_);
}

void Cover(int left ,int top,int right,int bottom) {
	setfillcolor(BLACK);  // ���������ɫΪ��ɫ
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

// ��ʼ������
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// �ƶ�����
void MoveStar(int i)
{
	// ����ԭ��������
	putpixel((int)star[i].x, star[i].y, 0);

	// ������λ��
	star[i].x += star[i].step;
	if (star[i].x > 640)	InitStar(i);

	// ��������
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

void Interface() {
	initgraph(648, 486);			// ������ͼ����
	IMAGE img_whole, img_start, img_rule, img_mode, img_choose, img_wall, img_NoWall, img;
	loadimage(&img_whole, "./����.png", 648, 486);
	loadimage(&img_start, "./��ʼ��Ϸ.png", 648, 486);
	loadimage(&img_rule, "./��Ϸ����.png", 648, 486);
	loadimage(&img_mode, "./ģʽ.png", 648, 486);
	loadimage(&img_wall, "./ѡ����ǽ.png", 648, 486);
	loadimage(&img_NoWall, "./ѡ����ǽ.png", 648, 486);
	loadimage(&img_choose, "./ѡ��.png", 648, 486);
	loadimage(&img, "./��ʼ.png", 108, 81);

	bool IsWall = true;
	bool IsStart = false;

Start:
	putimage(0, 0, &img_whole); // ���á���ʼ��Ϸ��ͼ��
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
				//��ʼ����������
				for (int i = 0; i < MAXSTAR; i++)
				{
					InitStar(i);
					star[i].x = rand() % 640;
				}

				// �����ǿգ���������˳�
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
				putimage(0, 0, &img_choose); // ��ʾimg_chooseͼƬ
				Text_return();
				while (true) {
					msg = GetMouseMsg();
					if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 184 && msg.x <= 483 && msg.y >= 218 && msg.y <= 258) {
						putimage(0, 0, &img_wall); // ��ʾimg_wallͼƬ
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
	closegraph();// �رջ�ͼ����
}

int main()
{
	srand((unsigned)time(NULL));	// �������
	Interface();
	return 0;
}
