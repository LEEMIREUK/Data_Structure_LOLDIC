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
			printf("다시 입력해주세요\n");
			break;
		}
		system("pause");
	}
	free(Champ);
	return 0;
}

void InitChamp()
{
	Champ[0] = { "가렌", "탑", 800, 0, 340, 176 };
	Champ[1] = { "쓰레쉬", "서포터", 560, 273, 335, 450 };
	Champ[2] = { "카서스", "정글", 540, 480, 335, 450 };
	Champ[3] = { "아리", "미드", 530, 480, 325, 550 };
	Champ[4] = { "갈리오", "미드", 562, 400, 335, 125 };
	Champ[5] = { "진", "원딜", 556, 300, 330, 550 };
	Champ[6] = { "브라움", "서폿", 547, 310, 335, 125 };
	Champ[7] = { "람머스", "정글", 800, 310, 335, 125 };
	Champ[8] = { "카직스", "정글", 575, 372, 350, 125 };
	Champ[9] = { "갱플랭크", "탑", 594, 270, 330, 125 };
	Champ[10] = { "아칼리", "미드", 550, 220, 345, 125 };
	Champ[11] = { "베인", "원딜", 515, 231, 330, 550 };
	Champ[12] = { "징크스", "원딜", 581, 245, 325, 525 };
	Champ[13] = { "리신", "정글", 571, 200, 345, 125 };
	Champ[14] = { "파이크", "서폿", 600, 415, 330, 150 };
	Champ[15] = { "세트", "탑", 530, 300, 340, 500 };
	Champ[16] = { "헤카림", "정글", 580, 327, 345, 175 };
	Champ[17] = { "피즈", "미드", 570, 317, 335, 175 };
	Champ[18] = { "레넥톤", "탑", 572, 100, 345, 125 };
	Champ[19] = { "탐켄치", "서폿", 800, 325, 335, 175 };
}

void Search()
{
	bool bSuccess = false;
	char szSearchName[32] = "";
	printf("검색할 챔피언의 이름: ");
	gets_s(szSearchName);

	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
	{
		if (!strcmp(szSearchName, Champ[i].szName))
		{
			printf("-----%s의 정보-----\n", Champ[i].szName);
			printf("이름: %s\n", Champ[i].szName);
			printf("체력: %d\n", Champ[i].iHp);
			printf("마나: %d\n", Champ[i].iMp);
			printf("속도: %d\n", Champ[i].iSpeed);
			printf("범위: %d\n", Champ[i].iRange);
			printf("위치: %s\n", Champ[i].cPosition);
			bSuccess = true;
		}
	}
	if (!bSuccess)
		printf("찾으시는 챔피언이 없습니다.\n");
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

	printf("---추가할 챔피언의 정보---\n");
	while (true)
	{
		printf("이름: ");
		gets_s(szFindName);
		for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
		{
			if (!strcmp(Champ[i].szName, szFindName))
			{
				printf("이미 챔피언이 존재합니다.\n");
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
		printf("체력: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iHp));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iHp > 0)
			break;
		else
			printf("잘못입력하셨습니다. 다시입력해주세요\n");
	}
	while (true)
	{
		Champ[CHAMPSIZE + iAddSize - 1].iMp = -1;
		printf("마나: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iMp));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iMp >= 0)
			break;
		else
			printf("잘못입력하셨습니다. 다시입력해주세요\n");
	}
	while (true)
	{
		Champ[CHAMPSIZE + iAddSize - 1].iSpeed = 0;
		printf("속도: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iSpeed));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iSpeed > 0)
			break;
		else
			printf("잘못입력하셨습니다. 다시입력해주세요\n");

	}
	while (true)
	{
		Champ[CHAMPSIZE + iAddSize - 1].iRange = 0;
		printf("범위: ");
		scanf_s("%d", &(Champ[CHAMPSIZE + iAddSize - 1].iRange));
		while (getchar() != '\n');
		if (Champ[CHAMPSIZE + iAddSize - 1].iRange > 0)
			break;
		else
			printf("잘못입력하셨습니다. 다시입력해주세요\n");

	}
	while (true)
	{
		printf("위치(탑, 정글, 미드, 원딜, 서폿): ");
		gets_s(cPos);
		if (!strcmp("탑", cPos) || !strcmp("정글", cPos) || !strcmp("미드", cPos) || !strcmp("원딜", cPos) || !strcmp("서폿", cPos))
		{
			strcpy_s(Champ[CHAMPSIZE + iAddSize - 1].cPosition, cPos);
			break;
		}
		else
			printf("탑, 정글, 미드, 원딜, 서폿 중에서 정해주세요\n");
	}
}

void Delete()
{
	bool bSuccess = false;
	char szDeleteName[32] = "";
	printf("삭제할 챔피언의 이름: ");
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
		printf("지우고자 하는 챔피언이 없습니다.\n");
}

void DeleteAll()
{
	bool bSuccess = false;
	char szDeletePos[32] = "";
	printf("삭제할 포지션: ");
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
		printf("지우고자 하는 포지션이 없습니다.\n");
}

void PrintAll()
{
	for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
	{
		if (Champ[i].iHp != 0)
		{
			printf("-----%s의 정보-----\n", Champ[i].szName);
			printf("이름: %s\n", Champ[i].szName);
			printf("체력: %d\n", Champ[i].iHp);
			printf("마나: %d\n", Champ[i].iMp);
			printf("속도: %d\n", Champ[i].iSpeed);
			printf("범위: %d\n", Champ[i].iRange);
			printf("위치: %s\n", Champ[i].cPosition);
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
			printf("-----%s의 정보-----\n", Champ[i].szName);
			printf("이름: %s\n", Champ[i].szName);
			printf("체력: %d\n", Champ[i].iHp);
			printf("마나: %d\n", Champ[i].iMp);
			printf("속도: %d\n", Champ[i].iSpeed);
			printf("범위: %d\n", Champ[i].iRange);
			printf("위치: %s\n", Champ[i].cPosition);
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