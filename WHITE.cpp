#include<stdio.h>
#include<easyx.h>
#include<time.h>
int Po[5];//每个黑块位置
int BX, BY;//每个黑块的坐标



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
			for (int i = 0; i < 4; i++)
			{
				Po[i] = Po[i + 1];
			}
			Po[0] = rand() % 4;
			printf("黑色\n");
		}
		else
		{
			printf("没有点到黑块\n");
			return true;
		}
		//检查
		for (int i = 0; i < 5; i++)
		{
			printf("%d = %d\n", i, Po[i]);
		}
		break;
	}
	return false;
}


//程序入口
int main()
{
	srand(time(NULL));//这个是拿时间当作种子来随机的！
	initgraph(480, 640, EX_SHOWCONSOLE);//5行4列
	Init_Black();
	Draw_game();
	while (1)
	{
		if (!play())
		{
			Draw_game();
			
		}
		
		
	}

	getchar();
	return 0;
}