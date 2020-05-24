#include <stdio.h>
#include <string>
#define CHAMPSIZE 20

typedef struct Champion
{
	char szName[32];
	char cPosition[32];
	int iHp;
	int iMp;
	int iSpeed;
	int iRange;
}CHAMPION;

void InitChamp(CHAMPION Champ[CHAMPSIZE]);
void Search(CHAMPION Champ[CHAMPSIZE]);
void PrintAll(CHAMPION Champ[CHAMPSIZE]);
void FindMaxHp(CHAMPION Champ[CHAMPSIZE]);

int main()
{
	int iSelect = 0;
	CHAMPION Champ[CHAMPSIZE];
	InitChamp(Champ);

	while (true)
	{
		system("cls");
		printf("1.Search  2.PrintAll  3.FindMaxHp\n");
		scanf_s("%d", &iSelect);
		while (getchar() != '\n');

		switch (iSelect)
		{
		case 1:
			Search(Champ);
			break;
		case 2:
			PrintAll(Champ);
			break;
		case 3:
			FindMaxHp(Champ);
			break;
		default:
			printf("�ٽ� �Է����ּ���\n");
			break;
		}
		system("pause");
	}
	return 0;
}

void InitChamp(CHAMPION Champ[CHAMPSIZE])
{
	Champ[0] = { "����", "ž", 800, 0, 340, 176 };
	Champ[1] = { "������", "������", 560, 273, 335, 450 };
	Champ[2] = { "ī����", "����", 540, 480, 335, 450 };
	Champ[3] = { "�Ƹ�", "�̵�", 530, 480, 325, 550 };
	Champ[4] = { "������", "�̵�", 562, 400, 335, 125 };
	Champ[5] = { "��", "����", 556, 300, 330, 550 };
	Champ[6] = { "����", "����", 547, 310, 335, 125 };
	Champ[7] = { "���ӽ�", "����", 800, 310, 335, 125 };
	Champ[8] = { "ī����", "����", 575, 372, 350, 125 };
	Champ[9] = { "���÷�ũ", "ž", 594, 270, 330, 125 };
	Champ[10] = { "��Į��", "�̵�", 550, 220, 345, 125 };
	Champ[11] = { "����", "����", 515, 231, 330, 550 };
	Champ[12] = { "¡ũ��", "����", 581, 245, 325, 525 };
	Champ[13] = { "����", "����", 571, 200, 345, 125 };
	Champ[14] = { "����ũ", "����", 600, 415, 330, 150 };
	Champ[15] = { "��Ʈ", "ž", 530, 300, 340, 500 };
	Champ[16] = { "��ī��", "����", 580, 327, 345, 175 };
	Champ[17] = { "����", "�̵�", 570, 317, 335, 175 };
	Champ[18] = { "������", "ž", 572, 100, 345, 125 };
	Champ[19] = { "Ž��ġ", "����", 800, 325, 335, 175 };
}

void Search(CHAMPION Champ[CHAMPSIZE])
{
	bool bSuccess = false;
	char szSearchName[32] = "";
	printf("�˻��� è�Ǿ��� �̸�: ");
	gets_s(szSearchName);

	for (int i = 0; i < CHAMPSIZE; ++i)
	{
		if (!strcmp(szSearchName, Champ[i].szName))
		{
			printf("-----%s�� ����-----\n", Champ[i].szName);
			printf("�̸�: %s\n", Champ[i].szName);
			printf("ü��: %d\n", Champ[i].iHp);
			printf("����: %d\n", Champ[i].iMp);
			printf("�ӵ�: %d\n", Champ[i].iSpeed);
			printf("����: %d\n", Champ[i].iRange);
			printf("��ġ: %s\n", Champ[i].cPosition);
			bSuccess = true;
		}
	}
	if (!bSuccess)
		printf("ã���ô� è�Ǿ��� �����ϴ�.\n");
}

void PrintAll(CHAMPION Champ[CHAMPSIZE])
{
	for (int i = 0; i < CHAMPSIZE; ++i)
	{
		printf("-----%s�� ����-----\n", Champ[i].szName);
		printf("�̸�: %s\n", Champ[i].szName);
		printf("ü��: %d\n", Champ[i].iHp);
		printf("����: %d\n", Champ[i].iMp);
		printf("�ӵ�: %d\n", Champ[i].iSpeed);
		printf("����: %d\n", Champ[i].iRange);
		printf("��ġ: %s\n", Champ[i].cPosition);
	}
}

void FindMaxHp(CHAMPION Champ[CHAMPSIZE])
{
	int iMaxHp = Champ[0].iHp;
	int iIndex = 0;
	for (int i = 0; i < CHAMPSIZE; ++i)
	{
		if (Champ[i].iHp > iMaxHp)
		{
			iMaxHp = Champ[i].iHp;
			iIndex = i;
		}
		else
			continue;
	}

	for (int i = 0; i < CHAMPSIZE; ++i)
	{
		if (Champ[i].iHp == iMaxHp)
		{
			printf("-----%s�� ����-----\n", Champ[i].szName);
			printf("�̸�: %s\n", Champ[i].szName);
			printf("ü��: %d\n", Champ[i].iHp);
			printf("����: %d\n", Champ[i].iMp);
			printf("�ӵ�: %d\n", Champ[i].iSpeed);
			printf("����: %d\n", Champ[i].iRange);
			printf("��ġ: %s\n", Champ[i].cPosition);
		}
	}
}