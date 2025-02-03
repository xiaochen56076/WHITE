#include<stdio.h>
#include<easyx.h>
#include<time.h>
int Po[5];//每个黑块位置
int BX, BY;//每个黑块的坐标
int Grade = 0;



void Init_Black()
{
	for (int i = 0; i < 5; i++)
	{
		Po[i] = rand() % 4;
		printf("%d = %d\n", i, Po[i]);//这个是为了方便检查位置才在控制台加的，只是检测而已😊
	}
}

void Draw_Black()
{
	for (int i = 0; i < 5; i++)
	{
		setfillcolor(BLACK);
		fillrectangle(Po[i] * 120, i * 128, (Po[i] + 1) * 120, (i + 1) * 128);
	}
}

void Draw_game()
 {
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	BeginBatchDraw();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fillrectangle(j * 120, i * 128, (j + 1) * 120, (i + 1) * 128);
		}
	}
	Draw_Black();
	EndBatchDraw();
 }

bool play()
{
	ExMessage msg;//定义一个变量来检测鼠标
	msg = getmessage();//获取鼠标的信息
	switch (msg.message)
	{
	case WM_LBUTTONDOWN://识别鼠标左键
		BX = msg.x / 120;
		BY = msg.y / 128;
		if (Po[4] == BX && BY == 4)
		{
			for (int i = 4; i > 0; i--)
			{
				Po[i] = Po[i - 1];
			}
			Po[0] = rand() % 4;
			printf("黑色\n");
			Grade++;
		}
		else
		{
			printf("没有点到黑块\n");
			return true;
		}
		//检查
		printf("测试结果：\n");
		for (int i = 0; i < 5; i++)
		{
			
			printf("\t%d = %d\n", i, Po[i]);
		}
		break;
	}
	return false;
}


//程序入口
int main()
{
	srand(time(NULL));//这个是拿时间当作种子来随机的！
	initgraph(480, 640);//5行4列
	Init_Black();
	Draw_game();
	while (1)
	{
		Draw_game();
		if (play())
		{
			wchar_t grade[128];
			swprintf_s(grade, _T("点击的块数是%d	分数是%d"), Grade, Grade * 10);
			int result = MessageBox(GetHWnd(), grade, _T("Game Over"), MB_RETRYCANCEL);
			if (result == IDRETRY)
			{
				Init_Black();
				Draw_game();
				Grade = 0;
				memset(grade, 0, sizeof(grade));
			}
			else
			{
				MessageBox(NULL, L"菜鸡，就这点就放弃了？", L"结束", MB_OK && MB_TOPMOST);
				exit(0);
			}
		}
	}
	return 0;
}