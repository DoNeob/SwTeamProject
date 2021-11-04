#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "characters.h"
#include "cursor.h"
#include "stage1.h"


void initCmd()
{
	//ȭ���� �ʹ� Ŀ�� �� ��Ʈ�Ͽ��� ���ư��� �ʾƿ� - ���ؿ�
	RemoveCursor();
	system("mode con cols=250 lines=50");
}


void initPlayer(player* p)
{
	p->x = 56;
	p->y = 33;
	p->life = 3;
	p->totalBalls = 0;
	p->balls = 0;
	p->stageNum = 1;
}

void initNPC(NPC* npc, int posX, int posY)
{
	npc->homeX = posX;
	npc->homeY = posY;
	npc->x = npc->homeX;
	npc->y = npc->homeY;
	npc->haveBall = 1;
}

void printStage()
{
	int i;

	for (i = 1; i < stage1X - 1; i++)
	{
		SetCurrentCursorPos(OriginX + (i * 2), OriginY);
		printf("��");
		SetCurrentCursorPos(OriginX + (i * 2), stage1Y + OriginY - 1);
		printf("��");
	}

	for (i = 0; i < stage1Y; i++)
	{
		if (i == 0)
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("��");
			SetCurrentCursorPos(OriginY + (stage1X - 1) * 2, i + OriginY);
			printf("��");
		}
		else if (i == stage1Y - 1)
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("��");
			SetCurrentCursorPos(OriginY + (stage1X - 1) * 2, i + OriginY);
			printf("��");
		}
		else
		{
			SetCurrentCursorPos(OriginX, i + OriginY);
			printf("��");
			SetCurrentCursorPos(OriginY + (stage1X - 1) * 2, i + OriginY);
			printf("��");
		}
	}

}

void printCloud(int stage[40][60])
{
	int i, j;
	int curX, curY;
	for (i = 1; i < stage1Y - 1; i++)
	{
		for (j = 1; j < stage1X - 1; j++)
		{
			curX = j * 2 + OriginX;
			curY = i + OriginY;
			SetCurrentCursorPos(curX, curY);
			if (stage[i][j] == 2)
				printf("��");
			else
				printf("  ");
		}
	}
}

void drawCharacter(player* p)
{
	int posX = OriginX + (p->x * 2);
	int posY = OriginY + p->y - 1;
	SetCurrentCursorPos(posX, posY++);
	printf("��");
	SetCurrentCursorPos(posX, posY++);
	printf("��");
	SetCurrentCursorPos(posX, posY);
	printf("��");
}

void drawNPC(NPC* npc)
{
	int posX = OriginX + (npc->x * 2);
	int posY = OriginY + npc->y - 1;
	SetCurrentCursorPos(posX, posY++);
	printf("��");
	SetCurrentCursorPos(posX, posY++);
	printf("��");
	SetCurrentCursorPos(posX, posY);
	printf("��");
}

void UpdateRecord(player* p)
{
	int curX = 135;
	int curY = 20;
	int i;
	SetCurrentCursorPos(curX, curY++);
	printf("���� ��������: %d", p->stageNum);
	SetCurrentCursorPos(curX, curY++);
	printf("���� ���: ");
	for (i = 0; i < p->life; i++)
		printf("��");
	SetCurrentCursorPos(curX, curY++);
	printf("���� �巡�� �� �� ����: %d", p->totalBalls);
	SetCurrentCursorPos(curX, curY++);
	printf("�̹� ������������ ���� �� ����: %d", p->balls);
}


int main()
{
	player p;
	NPC npc;

	initCmd();
	printStage();
	initPlayer(&p);

	initNPC(&npc, 8, 13);

	printCloud(stage1);
	drawCharacter(&p);
	drawNPC(&npc);

	UpdateRecord(&p);

	getchar();
	return 0;
}