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
			printf("다시 입력해주세요\n");
			break;
		}
		system("pause");
	}
	return 0;
}

void InitChamp(CHAMPION Champ[CHAMPSIZE])
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

void Search(CHAMPION Champ[CHAMPSIZE])
{
	bool bSuccess = false;
	char szSearchName[32] = "";
	printf("검색할 챔피언의 이름: ");
	gets_s(szSearchName);

	for (int i = 0; i < CHAMPSIZE; ++i)
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

void PrintAll(CHAMPION Champ[CHAMPSIZE])
{
	for (int i = 0; i < CHAMPSIZE; ++i)
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