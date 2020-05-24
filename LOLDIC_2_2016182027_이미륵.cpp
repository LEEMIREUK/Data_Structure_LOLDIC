#include <stdio.h>
#include <string>
#include <memory>
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

void InitChamp();
void Search();
void Insert();
void Delete();
void DeleteAll();
void PrintAll();
void FindMaxHp();
void SortByHp();

int iAddSize = 0;
CHAMPION* Champ = (CHAMPION*)malloc(sizeof(CHAMPION) * CHAMPSIZE);

int main()
{
	bool bExit = false;

	InitChamp();

	while (!bExit)
	{
		int iSelect = 0;
		system("cls");
		printf("1.Search  2.Insert  3.Delete  4.DeleteAll  5.PrintAll  6.FindMaxHp  7.SortByHp  8.Exit\n");
		scanf_s("%d", &iSelect);
		while (getchar() != '\n');

		switch (iSelect)
		{

		case 1:
			Search();
			break;
		case 2:
			Insert();
			break;
		case 3:
			Delete();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			PrintAll();
			break;
		case 6:
			FindMaxHp();
			break;
		case 7:
			SortByHp();
			break;
		case 8:
			bExit = true;
			break;
		default:
			printf("�ٽ� �Է����ּ���\n");
			break;
		}
		system("pause");
	}
	free(Champ);
	return 0;
}

void InitChamp()
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

void Search()
{
	bool bSuccess = false;
	char szSearchName[32] = "";
	printf("�˻��� è�Ǿ��� �̸�: ");
	gets_s(szSearchName);

	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
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

void Insert()
{
	iAddSize++;

	char szFindName[32] = "";
	char cPos[32] = "";
	int iGo = 0;
	CHAMPION* pTemp = NULL;
	pTemp = (CHAMPION*)malloc(sizeof(CHAMPION) * (CHAMPSIZE + iAddSize));
	memset(pTemp, 0, sizeof(CHAMPION) * (CHAMPSIZE + iAddSize));
	memcpy(pTemp, Champ, sizeof(CHAMPION) * (CHAMPSIZE + iAddSize - 1));
	Champ = NULL;
	Champ = pTemp;

	printf("---�߰��� è�Ǿ��� ����---\n");
	while (true)
	{
		printf("�̸�: ");
		gets_s(szFindName);
		for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
		{
			if (!strcmp(Champ[i].szName, szFindName))
			{
				printf("�̹� è�Ǿ��� �����մϴ�.\n");
				break;
			}
			else
			{
				if (i == CHAMPSIZE + iAddSize - 1)
				{
					strcpy_s(Champ[CHAMPSIZE + iAddSize - 1].szName, szFindName);
					iGo = 1;
				}
			}
		}
		if (iGo == 1)
			break;
	}
	while (true)
	{
		Champ[CHAMPSIZE + iAddSize - 1].iHp = 0;
		printf("ü��: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iHp));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iHp > 0)
			break;
		else
			printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���\n");
	}
	while (true)
	{
		Champ[CHAMPSIZE + iAddSize - 1].iMp = -1;
		printf("����: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iMp));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iMp >= 0)
			break;
		else
			printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���\n");
	}
	while (true)
	{
		Champ[CHAMPSIZE + iAddSize - 1].iSpeed = 0;
		printf("�ӵ�: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iSpeed));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iSpeed > 0)
			break;
		else
			printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���\n");

	}
	while (true)
	{
		Champ[CHAMPSIZE + iAddSize - 1].iRange = 0;
		printf("����: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iRange));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iRange > 0)
			break;
		else
			printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���\n");

	}
	while (true)
	{
		printf("��ġ(ž, ����, �̵�, ����, ����): ");
		gets_s(cPos);
		if (!strcmp("ž", cPos) || !strcmp("����", cPos) || !strcmp("�̵�", cPos) || !strcmp("����", cPos) || !strcmp("����", cPos))
		{
			strcpy_s(Champ[CHAMPSIZE + iAddSize - 1].cPosition, cPos);
			break;
		}
		else
			printf("ž, ����, �̵�, ����, ���� �߿��� �����ּ���\n");
	}
}

void Delete()
{
	bool bSuccess = false;
	char szDeleteName[32] = "";
	printf("������ è�Ǿ��� �̸�: ");
	gets_s(szDeleteName);

	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
	{
		if (!strcmp(szDeleteName, Champ[i].szName))
		{
			Champ[i] = { NULL };
			bSuccess = true;
		}
	}
	if (!bSuccess)
		printf("������� �ϴ� è�Ǿ��� �����ϴ�.\n");
}

void DeleteAll()
{
	bool bSuccess = false;
	char szDeletePos[32] = "";
	printf("������ ������: ");
	gets_s(szDeletePos);

	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
	{
		if (!strcmp(szDeletePos, Champ[i].cPosition))
		{
			Champ[i] = { NULL };
			bSuccess = true;
		}
	}
	if (!bSuccess)
		printf("������� �ϴ� �������� �����ϴ�.\n");
}

void PrintAll()
{
	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
	{
		if (Champ[i].iHp != 0)
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

void FindMaxHp()
{
	int iMaxHp = Champ[0].iHp;
	int iIndex = 0;
	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
	{
		if (Champ[i].iHp > iMaxHp)
		{
			iMaxHp = Champ[i].iHp;
			iIndex = i;
		}
		else
			continue;
	}

	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
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

void SortByHp()
{
	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
	{
		for (int j = 0; j < CHAMPSIZE + iAddSize - 1 - i; ++j)
		{
			if (Champ[j].iHp < Champ[j + 1].iHp)
			{
				CHAMPION Temp = Champ[j];
				Champ[j] = Champ[j + 1];
				Champ[j + 1] = Temp;
			}
		}
	}
}