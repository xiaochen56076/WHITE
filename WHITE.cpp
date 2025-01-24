#include<stdio.h>
#include<easyx.h>
#include<time.h>
int Po[5];//ÿ���ڿ�λ��
int BX, BY;



void Init_Black()
{
	for (int i = 0; i < 5; i++)
	{
		Po[i] = rand() % 4;
		printf("%d = %d\n", i, Po[i]);//�����Ϊ�˷�����λ�ò��ڿ���̨�ӵģ�ֻ�Ǽ�����
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
	ExMessage msg;//����һ��������������
	msg = getmessage();//��ȡ������Ϣ
	switch (msg.message)
	{
	case WM_LBUTTONDOWN://ʶ��������
		BX = msg.x / 120;
		BY = msg.y / 128;
		if (Po[4] == BX && BY == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				Po[i] = Po[i + 1];
			}
			Po[0] = rand() % 4;
			printf("��ɫ\n");
		}
		else
		{
			printf("û�е㵽�ڿ�\n");
			return true;
		}
		break;
	}
	return false;
}


//�������
int main()
{
	srand(time(NULL));//�������ʱ�䵱������������ģ�
	initgraph(480, 640, EX_SHOWCONSOLE);//5��4��
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