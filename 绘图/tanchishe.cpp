#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
#include<mmsystem.h>//�������ֵĿ�
#pragma comment(lib,"winmm.lib")//д�����ֵ�

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

struct shiwu {
	int x;//ʳ���x����
	int y;//ʳ���y����
	int flag;//ʳ��Ĵ���
}shiwu;


enum fx
{
	right, left, up, down
};



struct she {
	int x[200];
	int y[200];
	int jie;//�ߵĽ���
	int fx;//���ƶ��ķ���
	int sihuo;//�ж����Ƿ��������ǻ�
}she;


void qiang()
{
	int i;
	for (i = 0; i <= 640; i += 10)
	{
		setlinecolor(RED);

		setfillcolor(WHITE);

		setlinestyle(PS_SOLID, 2);

		fillrectangle(10 + i, 10, 20 + i, 20);
	}
	for (i = 0; i <= 640; i += 10)
	{
		setlinecolor(RED);

		setfillcolor(WHITE);

		setlinestyle(PS_SOLID, 2);

		fillrectangle(10 + i, 450, 20 + i, 460);
	}
	for (i = 0; i <= 430; i += 10)
	{
		setlinecolor(RED);

		setfillcolor(WHITE);

		setlinestyle(PS_SOLID, 2);

		fillrectangle(650 ,20+i , 660 , 30+i);
	}
	for (i = 0; i <= 430; i += 10)
	{
		setlinecolor(RED);

		setfillcolor(WHITE);

		setlinestyle(PS_SOLID, 2);

		fillrectangle(10,20+i , 20 , 30+i);
	}
	
}


int Sudu()
{
	int n;
	gotoxy(50, 8);
	printf("�� �� 1 \n");
	gotoxy(50, 10);
	printf("�� �� 2 \n");
	gotoxy(50, 12);
	printf("�� �� 3 \n");
	gotoxy(50, 14);
	printf("�� �� 4 \n");
	gotoxy(50, 16);
	printf("�� ѡ ��");
	gotoxy(60, 16);
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		return 70;
	case 2:
		return 50;
	case 3:
		return 30;
	case 4:
		return 10;
	defaut:
		cleardevice();
		Sudu();
	}
	
}


void dingyishe()
{
	she.jie = 3;//��ʾ�ߵĳ�ʼ�Ľ���
	she.x[0] = 300;
	she.y[0] = 260;
	she.x[1] = 290;
	she.y[1] = 260;
	she.x[2] = 280;
	she.y[2] = 260;
	she.fx = right;//��ʾ��������
	she.sihuo = 1;//��ʾ��û����
}

void dingyishiwu()
{
	shiwu.x = 40 + rand() % 600;
	shiwu.y = 40 + rand() % 400;
	shiwu.flag = 1;
	for (int i = 0; i < she.jie; i++)//��ʾʳ�ﲻ�ܳ�����������
	{
		if (she.x[i] == shiwu.x&&she.y[i] == shiwu.y)
		{
			shiwu.x = 40 + rand() % 600;
			shiwu.y = 40 + rand() % 400;
		}
	}
	
}

void huashe()
{
	for (int i = 0; i < she.jie; i++)
	{
		setlinecolor(BLUE);
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(she.x[i], she.y[i], she.x[i] + 10, she.y[i] + 10);
	}
}

void huashiwu()
{
	setlinecolor(BLUE);
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(shiwu.x, shiwu.y, shiwu.x + 10, shiwu.y + 10);
}

void yidong()
{
	for (int i = she.jie - 1; i > 0; i--)
	{
		she.x[i] = she.x[i - 1];
		she.y[i] = she.y[i - 1];//��ʾ�������ƶ�
	}
	switch (she.fx)//��ʾ��ͷ���ƶ�
	{
	case right:she.x[0] += 10;
		break;
	case left:she.x[0] -= 10;
		break;
	case up:she.y[0] -= 10;
		break;
	case down:she.y[0] += 10;
		break;
	}
}


void chaozuo()
{
	char key = _getch();
	switch (key)
	{
	case 'w':
	case 'W':
	case 72:
		if (she.fx != down)//�ж��Ƿ����෴�ķ���
			she.fx = up; 
		break;
	case 's':
	case 'S':
	case 80:
		if (she.fx != up)//�ж��Ƿ����෴�ķ���
			she.fx = down;
		break;
	case 'a':
	case 'A':
	case 75:
		if (she.fx != right)//�ж��Ƿ����෴�ķ���
			she.fx = left;
		break;
	case 'd':
	case 'D':
	case 77:
		if (she.fx != left)//�ж��Ƿ����෴�ķ���
			she.fx = right;
		break;
	}
}
//void settextstyle(int font, int direction, int charsize);
//void outtextxy(int x, int y, char *textstring);

void GameOver()
{
	cleardevice();
	setcolor(RED);
	
	settextstyle(100, 0, "����");
	outtextxy(200, 250, "��Ϸ������");
	Sleep(500);
	
	
}
void chishiwu()
{
	if (she.x[0] >= shiwu.x&&she.x[0]<=shiwu.x+10&&she.y[0] <= shiwu.y&&she.y[0]>=shiwu.y-10)
	{
		she.jie++;
		shiwu.flag = 0;
	}
}
void zhuangqiang()
{
	if (she.x[0] < 10 || she.x[0]>650 || she.y[0] > 450 || she.y[0] < 10)//��ʾ��ײǽ
	{
		GameOver();
		she.sihuo = 0;//��ʾ������
	}
}
void zhuangziji()
{
	for (int i = 3; i < she.jie; i++)
	{
		if (she.x[0] == she.x[i] && she.y[0] == she.y[i])//��ʾ��ײ�Լ�
		{
			GameOver();
			she.sihuo = 0;
		}
	}
}
 int main()
{
	
	int sudu;
	sudu= Sudu();
	srand((unsigned int)time(0));
	initgraph(800, 800);
	setbkcolor(RGB(37, 128, 84));
	cleardevice();
	
	dingyishe();
	huashe();
	
	while (1)
	{
		
		cleardevice();
		qiang();
		huashe();
		yidong();
		
		if (shiwu.flag == 0)
		{
			dingyishiwu();
		}
		if (_kbhit())//�ж��Ƿ��а�������
		{
			chaozuo();
		}
		huashiwu();
		chishiwu();
		zhuangqiang();
		zhuangziji();

		Sleep(sudu);
	}
	_getch();
	closegraph();
	return 0;
}


