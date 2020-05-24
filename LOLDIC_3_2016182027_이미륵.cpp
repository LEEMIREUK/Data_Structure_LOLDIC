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
void Search_R(char*, int, bool);
void Insert_R(int);
void Delete_R(char*, int, bool);
void DeleteAll_R(char*, int, bool);
void PrintAll_R(int);
void FindMaxHp_R(int, int, int);
void SortByHp_R(int);

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
		printf("1.Search_R  2.Insert_R  3.Delete_R  4.DeleteAll_R  5.PrintAll_R  6.FindMaxHp_R  7.SortByHp_R  8.Exit\n");
		scanf_s("%d", &iSelect);
		while (getchar() != '\n');

		switch (iSelect)
		{
		case 1:
		{
			int iCount = 0;
			bool bSuccess = false;
			char szSearchName[32] = "";
			printf("검색할 챔피언의 이름: ");
			gets_s(szSearchName);
			Search_R(szSearchName, iCount, bSuccess);
			break;
		}
		case 2:
		{
			int iCount = 0;
			for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
			{
				if (Champ[i].iHp != 0)
				{
					iAddSize++;
					CHAMPION* pTemp = NULL;
					pTemp = (CHAMPION*)malloc(sizeof(CHAMPION) * (CHAMPSIZE + iAddSize));
					memset(pTemp, 0, sizeof(CHAMPION) * (CHAMPSIZE + iAddSize));
					memcpy(pTemp, Champ, sizeof(CHAMPION) * (CHAMPSIZE + iAddSize - 1));
					Champ = NULL;
					Champ = pTemp;
				}
			}
			Insert_R(iCount);
			break;
		}
		case 3:
		{
			int iCount = 0;
			bool bSuccess = false;
			char szDeleteName[32] = "";
			printf("삭제할 챔피언의 이름: ");
			gets_s(szDeleteName);
			Delete_R(szDeleteName, iCount, bSuccess);
			break;
		}
		case 4:
		{
			int iCount = 0;
			bool bSuccess = false;
			char szDeletePos[32] = "";
			printf("삭제할 포지션의 이름: ");
			gets_s(szDeletePos);
			DeleteAll_R(szDeletePos, iCount, bSuccess);
			break;
		}
		case 5:
		{
			int iCount = 0;
			PrintAll_R(iCount);
			break;
		}
		case 6:
		{
			int iCount = 0;
			int iMaxHp = 0;
			int iIndex = 0;
			FindMaxHp_R(iMaxHp, iIndex, iCount);
			break;
		}
		case 7:
		{
			int iCount = 0;
			SortByHp_R(iCount);
			break;
		}
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
	Champ[3] = { NULL };
	Champ[4] = { "갈리오", "미드", 562, 400, 335, 125 };
	Champ[5] = { "진", "원딜", 556, 300, 330, 550 };
	Champ[6] = { "브라움", "서폿", 547, 310, 335, 125 };
	Champ[7] = { "람머스", "정글", 800, 310, 335, 125 };
	Champ[8] = { "카직스", "정글", 575, 372, 350, 125 };
	Champ[9] = { NULL };
	Champ[10] = { "아칼리", "미드", 550, 220, 345, 125 };
	Champ[11] = { "베인", "원딜", 515, 231, 330, 550 };
	Champ[12] = { "징크스", "원딜", 581, 245, 325, 525 };
	Champ[13] = { NULL };
	Champ[14] = { "파이크", "서폿", 600, 415, 330, 150 };
	Champ[15] = { "세트", "탑", 530, 300, 340, 500 };
	Champ[16] = { "헤카림", "정글", 580, 327, 345, 175 };
	Champ[17] = { "피즈", "미드", 570, 317, 335, 175 };
	Champ[18] = { "레넥톤", "탑", 572, 100, 345, 125 };
	Champ[19] = { "탐켄치", "서폿", 800, 325, 335, 175 };
}

void Search_R(char* szSearchName, int iCount, bool bSuccess)
{
	if (!strcmp(szSearchName, Champ[iCount].szName))
	{
		printf("-----%s의 정보-----\n", Champ[iCount].szName);
		printf("이름: %s\n", Champ[iCount].szName);
		printf("체력: %d\n", Champ[iCount].iHp);
		printf("마나: %d\n", Champ[iCount].iMp);
		printf("속도: %d\n", Champ[iCount].iSpeed);
		printf("범위: %d\n", Champ[iCount].iRange);
		printf("위치: %s\n", Champ[iCount].cPosition);
		bSuccess = true;
	}

	if (iCount < CHAMPSIZE + iAddSize - 1)
		Search_R(szSearchName, iCount + 1, bSuccess);

	if (iCount == CHAMPSIZE + iAddSize - 1)
		if (!bSuccess)
			printf("찾으시는 챔피언이 없습니다.\n");
}

void Insert_R(int iCount)
{
	if (Champ[iCount].iHp == 0)
	{
		char szFindName[32] = "";
		char cPos[32] = "";
		int iGo = 0;
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
						strcpy_s(Champ[iCount].szName, szFindName);
						iGo = 1;
					}
				}
			}
			if (iGo == 1)
				break;
		}

		while (true)
		{
			Champ[iCount].iHp = 0;
			printf("체력: ");
			scanf_s("%d", &(Champ[iCount].iHp));
			while (getchar() != '\n');
			if (Champ[iCount].iHp > 0)
				break;
			else
				printf("잘못입력하셨습니다. 다시입력해주세요\n");
		}
		while (true)
		{
			Champ[iCount].iMp = -1;
			printf("마나: ");
			scanf_s("%d", &(Champ[iCount].iMp));
			while (getchar() != '\n');
			if (Champ[iCount].iMp >= 0)
				break;
			else
				printf("잘못입력하셨습니다. 다시입력해주세요\n");
		}
		while (true)
		{
			Champ[iCount].iSpeed = 0;
			printf("속도: ");
			scanf_s("%d", &(Champ[iCount].iSpeed));
			while (getchar() != '\n');
			if (Champ[iCount].iSpeed > 0)
				break;
			else
				printf("잘못입력하셨습니다. 다시입력해주세요\n");

		}
		while (true)
		{
			Champ[iCount].iRange = 0;
			printf("범위: ");
			scanf_s("%d", &(Champ[iCount].iRange));
			while (getchar() != '\n');
			if (Champ[iCount].iRange > 0)
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
				strcpy_s(Champ[iCount].cPosition, cPos);
				break;
			}
			else
				printf("탑, 정글, 미드, 원딜, 서폿 중에서 정해주세요\n");
		}
		return;
	}
	
	if(iCount < CHAMPSIZE + iAddSize -1)
		Insert_R(iCount + 1);
}

void Delete_R(char* szDeleteName, int iCount, bool bSuccess)
{
	if (!strcmp(szDeleteName, Champ[iCount].szName))
	{
		Champ[iCount] = { NULL };
		bSuccess = true;
	}

	if (iCount < CHAMPSIZE + iAddSize - 1)
		Delete_R(szDeleteName, iCount + 1, bSuccess);

	if (iCount == CHAMPSIZE + iAddSize - 1)
		if (!bSuccess)
			printf("찾으시는 챔피언이 없습니다.\n");
}

void DeleteAll_R(char* szDeletePos, int iCount, bool bSuccess)
{
	if (!strcmp(szDeletePos, Champ[iCount].cPosition))
	{
		Champ[iCount] = { NULL };
		bSuccess = true;
	}

	if (iCount < CHAMPSIZE + iAddSize - 1)
		DeleteAll_R(szDeletePos, iCount + 1, bSuccess);

	if (iCount == CHAMPSIZE + iAddSize - 1)
	{
		if (!bSuccess)
			printf("찾으시는 챔피언이 없습니다.\n");
	}
}

void PrintAll_R(int iCount)
{
	if (Champ[iCount].iHp != 0)
	{
		printf("-----%s의 정보-----\n", Champ[iCount].szName);
		printf("이름: %s\n", Champ[iCount].szName);
		printf("체력: %d\n", Champ[iCount].iHp);
		printf("마나: %d\n", Champ[iCount].iMp);
		printf("속도: %d\n", Champ[iCount].iSpeed);
		printf("범위: %d\n", Champ[iCount].iRange);
		printf("위치: %s\n", Champ[iCount].cPosition);
	}
	if (iCount < CHAMPSIZE + iAddSize - 1)
		PrintAll_R(iCount + 1);
}

void FindMaxHp_R(int iMaxHp, int iIndex, int iCount)
{
	if (iCount == 0)
		iMaxHp = Champ[0].iHp;
	if (Champ[iCount + 1].iHp > iMaxHp)
	{
		iMaxHp = Champ[iCount + 1].iHp;
		iIndex = iCount + 1;
	}
	if (iCount < CHAMPSIZE + iAddSize - 2)
		FindMaxHp_R(iMaxHp, iIndex, iCount + 1);
	else
	{
		printf("채력이 가장 높은 챔피언의 정보\n");
		for (int i = 0; i < CHAMPSIZE + iAddSize; ++i)
		{
			if (Champ[i].iHp == iMaxHp)
			{
				printf("----------------------\n");
				printf("이름: %s\n", Champ[i].szName);
				printf("체력: %d\n", Champ[i].iHp);
				printf("마나: %d\n", Champ[i].iMp);
				printf("속도: %d\n", Champ[i].iSpeed);
				printf("범위: %d\n", Champ[i].iRange);
				printf("위치: %s\n", Champ[i].cPosition);
			}
		}
	}
}

void SortByHp_R(int iCount)
{
	if (Champ[iCount].iHp < Champ[iCount + 1].iHp)
	{
		CHAMPION Temp = Champ[iCount];
		Champ[iCount] = Champ[iCount + 1];
		Champ[iCount + 1] = Temp;

		if (iCount >= 1)
			SortByHp_R(iCount - 1);
	}

	if (iCount < CHAMPSIZE + iAddSize - 2)
		SortByHp_R(iCount + 1);
}