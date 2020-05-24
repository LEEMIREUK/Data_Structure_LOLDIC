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
    Champion* pNext = NULL;
}NODE;

NODE* pHead = (NODE*)malloc(sizeof(NODE));
NODE* pSort = (NODE*)malloc(sizeof(NODE));

void InitChamp(NODE*);
void Search_SL();
void Insert_SL();
void Delete_SL();
void DeleteAll_SL();
void PrintAll_SL();
void FindMaxHp_SL();
void SortByHp_SL();

void Array2LinkedList(NODE* pChamp)
{
    InitChamp(pChamp);
    pHead->pNext = &pChamp[0];
    for (int i = 0; i < CHAMPSIZE; ++i)
    {
        if (i < CHAMPSIZE - 1)
            pChamp[i].pNext = &pChamp[i + 1];
        else if (i == CHAMPSIZE - 1)
            pChamp[i].pNext = &pChamp[0];
    }
}

int main()
{
    bool bExit = false;
    NODE Champ[CHAMPSIZE];
    Array2LinkedList(Champ);

    while (!bExit)
    {
        int iSelect = 0;
        system("cls");
        printf("1.Search_SL  2.Insert_SL  3.Delete_SL  4.DeleteAll_SL  5.PrintAll_SL  6.FindMaxHp_SL  7.SortByHp_SL  8.Exit\n");
        scanf_s("%d", &iSelect);
        while (getchar() != '\n');

        switch (iSelect)
        {
        case 1:
            Search_SL();
            break;
        case 2:
            Insert_SL();
            break;
        case 3:
            Delete_SL();
            break;
        case 4:
            DeleteAll_SL();
            break;
        case 5:
            PrintAll_SL();
            break;
        case 6:
            FindMaxHp_SL();
            break;
        case 7:
            SortByHp_SL();
            printf("정렬되었습니다.\n");
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
    if(pHead != NULL)
        free(pHead);
    return 0;
}

void InitChamp(NODE* pChamp)
{
    pChamp[0] = { "가렌", "탑", 800, 0, 340, 176 };
    pChamp[1] = { "쓰레쉬", "서폿", 560, 273, 335, 450 };
    pChamp[2] = { "카서스", "정글", 540, 480, 335, 450 };
    pChamp[3] = { "애쉬", "원딜", 536, 480, 325, 550 };
    pChamp[4] = { "갈리오", "미드", 562, 400, 335, 125 };
    pChamp[5] = { "진", "원딜", 556, 300, 330, 550 };
    pChamp[6] = { "브라움", "서폿", 547, 310, 335, 125 };
    pChamp[7] = { "람머스", "정글", 800, 310, 335, 125 };
    pChamp[8] = { "카직스", "정글", 575, 372, 350, 125 };
    pChamp[9] = { "오른", "탑", 600, 270, 345, 125 };
    pChamp[10] = { "아칼리", "미드", 550, 220, 345, 125 };
    pChamp[11] = { "베인", "원딜", 515, 231, 330, 550 };
    pChamp[12] = { "징크스", "원딜", 581, 245, 325, 525 };
    pChamp[13] = { "리신", "정글", 571, 200, 345, 125 };
    pChamp[14] = { "파이크", "서폿", 600, 415, 330, 150 };
    pChamp[15] = { "세트", "탑", 530, 300, 340, 500 };
    pChamp[16] = { "헤카림", "정글", 580, 327, 345, 175 };
    pChamp[17] = { "피즈", "미드", 570, 317, 335, 175 };
    pChamp[18] = { "레넥톤", "탑", 572, 100, 345, 125 };
    pChamp[19] = { "탐켄치", "서폿", 800, 325, 335, 175 };
}

void Search_SL()
{
    bool bSuccess = false;
    char szSearchName[32] = "";
    printf("검색할 챔피언의 이름: ");
    gets_s(szSearchName);

    if (pHead->pNext != NULL)
    {
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (!strcmp(szSearchName, p->szName))
            {
                printf("-----%s의 정보-----\n", p->szName);
                printf("이름: %s\n", p->szName);
                printf("체력: %d\n", p->iHp);
                printf("마나: %d\n", p->iMp);
                printf("속도: %d\n", p->iSpeed);
                printf("범위: %d\n", p->iRange);
                printf("위치: %s\n", p->cPosition);
                bSuccess = true;
            }
            if ((p->pNext->pNext == pHead->pNext) && (!strcmp(szSearchName, p->pNext->szName)))
            {
                printf("-----%s의 정보-----\n", p->pNext->szName);
                printf("이름: %s\n", p->pNext->szName);
                printf("체력: %d\n", p->pNext->iHp);
                printf("마나: %d\n", p->pNext->iMp);
                printf("속도: %d\n", p->pNext->iSpeed);
                printf("범위: %d\n", p->pNext->iRange);
                printf("위치: %s\n", p->pNext->cPosition);
                bSuccess = true;
            }
        }
    }
    if (!bSuccess)
        printf("찾으시는 챔피언이 없습니다.\n");
}

void Insert_SL()
{
    SortByHp_SL();

    char szFindName[32] = "";
    char cPos[32] = "";
    int iGo = 0;
    NODE* pNew = (NODE*)malloc(sizeof(NODE));
  
    for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
    {
        if (p->pNext->pNext == pHead->pNext)
        {
            p->pNext->pNext = pNew;
            pNew->pNext = pHead->pNext;
        }
    }

    printf("---추가할 챔피언의 정보---\n");
    while (true)
    {
        printf("이름: ");
        gets_s(szFindName);
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (!strcmp(szFindName, p->szName))
            {
                printf("이미 챔피언이 존재합니다.\n");
                break;
            }
            else
                iGo = 1;
            if ((p->pNext->pNext == pHead->pNext) && (!strcmp(szFindName, p->pNext->szName)))
            {
                printf("이미 챔피언이 존재합니다.\n");
                break;
            }
            else
                iGo = 1;
        }
        if (iGo == 1)
            break;
    }
    strcpy_s(pNew->szName, szFindName);

    while (true)
    {
        pNew->iHp = 0;
        printf("체력: ");
        scanf_s("%d", &(pNew->iHp));
        while (getchar() != '\n');
        if (pNew->iHp > 0)
            break;
        else
            printf("잘못입력하셨습니다. 다시입력해주세요\n");
    }
    while (true)
    {
        pNew->iMp = -1;
        printf("마나: ");
        scanf_s("%d", &(pNew->iMp));
        while (getchar() != '\n');
        if (pNew->iMp >= 0)
            break;
        else
            printf("잘못입력하셨습니다. 다시입력해주세요\n");
    }
    while (true)
    {
        pNew->iSpeed = 0;
        printf("속도: ");
        scanf_s("%d", &(pNew->iSpeed));
        while (getchar() != '\n');
        if (pNew->iSpeed > 0)
            break;
        else
            printf("잘못입력하셨습니다. 다시입력해주세요\n");

    }
    while (true)
    {
        pNew->iRange = 0;
        printf("범위: ");
        scanf_s("%d", &(pNew->iRange));
        while (getchar() != '\n');
        if (pNew->iRange > 0)
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
            strcpy_s(pNew->cPosition, cPos);
            break;
        }
        else
            printf("탑, 정글, 미드, 원딜, 서폿 중에서 정해주세요\n");
    }
}

void Delete_SL()
{
    bool bSuccess = false;
    char szDeleteName[32] = "";
    printf("삭제할 챔피언의 이름: ");
    gets_s(szDeleteName);
    if (pHead->pNext != NULL)
    {
        if (pHead->pNext->pNext == pHead->pNext)
        {
            if (!strcmp(szDeleteName, pHead->pNext->szName))
            {
                pHead->pNext = NULL;
                bSuccess = true;
            }
        }
        else
        {
            for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
            {

                if (!strcmp(szDeleteName, p->szName))
                {
                    if (p == pHead->pNext)
                    {
                        for (NODE* pTemp = pHead->pNext; pTemp->pNext != pHead->pNext; pTemp = pTemp->pNext)
                        {
                            if (pTemp->pNext->pNext == pHead->pNext)
                            {
                                pHead->pNext = p->pNext;
                                pTemp->pNext->pNext = pHead->pNext;
                            }
                        }
                    }
                    else
                    {
                        for (NODE* pTemp = pHead->pNext; pTemp->pNext != pHead->pNext; pTemp = pTemp->pNext)
                        {
                            if (pTemp->pNext == p)
                                pTemp->pNext = p->pNext;
                        }
                    }
                    bSuccess = true;
                }
                else if ((p->pNext->pNext == pHead->pNext) && (!strcmp(szDeleteName, p->pNext->szName)))
                {
                    p->pNext = pHead->pNext;
                    bSuccess = true;
                }
            }
        }
    }
    if (!bSuccess)
        printf("지우고자 하는 챔피언이 없습니다.\n");

}

void DeleteAll_SL()
{
    bool bSuccess = false;
    char szDeletePos[32] = "";
    printf("삭제할 포지션: ");
    gets_s(szDeletePos);


    if (pHead->pNext != NULL)
    {
        if (pHead->pNext->pNext == pHead->pNext)
        {
            if (!strcmp(szDeletePos, pHead->pNext->cPosition))
            {
                pHead->pNext = NULL;
                bSuccess = true;
            }
        }
        else
        {
            for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
            {

                if (!strcmp(szDeletePos, p->cPosition))
                {
                    if (p == pHead->pNext)
                    {
                        for (NODE* pTemp = pHead->pNext; pTemp->pNext != pHead->pNext; pTemp = pTemp->pNext)
                        {
                            if (pTemp->pNext->pNext == pHead->pNext)
                            {
                                pHead->pNext = p->pNext;
                                pTemp->pNext->pNext = pHead->pNext;
                            }
                        }
                    }
                    else
                    {
                        for (NODE* pTemp = pHead->pNext; pTemp->pNext != pHead->pNext; pTemp = pTemp->pNext)
                        {
                            if (pTemp->pNext == p)
                                pTemp->pNext = p->pNext;
                        }
                    }
                    bSuccess = true;
                }
                else if ((p->pNext->pNext == pHead->pNext) && (!strcmp(szDeletePos, p->pNext->cPosition)))
                {
                    p->pNext = pHead->pNext;
                    bSuccess = true;
                }
                if (pHead->pNext->pNext == pHead->pNext)
                {
                    pHead->pNext = NULL;
                    bSuccess = true;
                    break;
                }
            }
        }
    }
    if (!bSuccess)
        printf("지우고자 하는 포지션이 없습니다.\n");
 }

void PrintAll_SL()
{
    if (pHead->pNext != NULL)
    {
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (p->iHp != 0)
            {
                printf("-----%s의 정보-----\n", p->szName);
                printf("이름: %s\n", p->szName);
                printf("체력: %d\n", p->iHp);
                printf("마나: %d\n", p->iMp);
                printf("속도: %d\n", p->iSpeed);
                printf("범위: %d\n", p->iRange);
                printf("위치: %s\n", p->cPosition);
            }
            if ((p->pNext->pNext == pHead->pNext) && (p->iHp != 0))
            {
                printf("-----%s의 정보-----\n", p->pNext->szName);
                printf("이름: %s\n", p->pNext->szName);
                printf("체력: %d\n", p->pNext->iHp);
                printf("마나: %d\n", p->pNext->iMp);
                printf("속도: %d\n", p->pNext->iSpeed);
                printf("범위: %d\n", p->pNext->iRange);
                printf("위치: %s\n", p->pNext->cPosition);
            }
        }
        if (pHead->pNext->pNext == pHead->pNext)
        {
            printf("-----%s의 정보-----\n", pHead->pNext->szName);
            printf("이름: %s\n", pHead->pNext->szName);
            printf("체력: %d\n", pHead->pNext->iHp);
            printf("마나: %d\n", pHead->pNext->iMp);
            printf("속도: %d\n", pHead->pNext->iSpeed);
            printf("범위: %d\n", pHead->pNext->iRange);
            printf("위치: %s\n", pHead->pNext->cPosition);
        }
    }
}

void FindMaxHp_SL()
{
    if (pHead->pNext != NULL)
    {
        int iMaxHp = 0;
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (p->iHp > iMaxHp)
                iMaxHp = p->iHp;
            else if (p->pNext->pNext->iHp > iMaxHp)
                iMaxHp = p->pNext->iHp;
            else
                continue;
        }

        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (p->iHp == iMaxHp)
            {
                printf("-----%s의 정보-----\n", p->szName);
                printf("이름: %s\n", p->szName);
                printf("체력: %d\n", p->iHp);
                printf("마나: %d\n", p->iMp);
                printf("속도: %d\n", p->iSpeed);
                printf("범위: %d\n", p->iRange);
                printf("위치: %s\n", p->cPosition);
            }
            if ((p->pNext->pNext == pHead->pNext) && (p->pNext->iHp == iMaxHp))
            {
                printf("-----%s의 정보-----\n", p->pNext->szName);
                printf("이름: %s\n", p->pNext->szName);
                printf("체력: %d\n", p->pNext->iHp);
                printf("마나: %d\n", p->pNext->iMp);
                printf("속도: %d\n", p->pNext->iSpeed);
                printf("범위: %d\n", p->pNext->iRange);
                printf("위치: %s\n", p->pNext->cPosition);
            }
        }
        if (pHead->pNext->pNext == pHead->pNext)
        {
            printf("-----%s의 정보-----\n", pHead->pNext->szName);
            printf("이름: %s\n", pHead->pNext->szName);
            printf("체력: %d\n", pHead->pNext->iHp);
            printf("마나: %d\n", pHead->pNext->iMp);
            printf("속도: %d\n", pHead->pNext->iSpeed);
            printf("범위: %d\n", pHead->pNext->iRange);
            printf("위치: %s\n", pHead->pNext->cPosition);
        }
    }
}

void SortByHp_SL()
{
    NODE* pMax;
    NODE* pTemp = NULL;
    pSort->pNext = NULL;
    while (pHead->pNext != NULL)
    {
        pMax = pHead->pNext;
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (pMax->iHp < p->pNext->iHp)
                pMax = p->pNext;
            if ((p->pNext->pNext == pHead->pNext) && (pMax->iHp < p->pNext->iHp))
                pMax = p->pNext;
        }
        if (pHead->pNext != NULL)
        {
            if (pHead->pNext->pNext == pHead->pNext)
            {
                if (!strcmp(pMax->szName, pHead->pNext->szName))
                {
                    pHead->pNext = NULL;
                }
            }
            else
            {
                for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
                {

                    if (!strcmp(pMax->szName, p->szName))
                    {
                        if (p == pHead->pNext)
                        {
                            for (NODE* pTemp = pHead->pNext; pTemp->pNext != pHead->pNext; pTemp = pTemp->pNext)
                            {
                                if (pTemp->pNext->pNext == pHead->pNext)
                                {
                                    pHead->pNext = p->pNext;
                                    pTemp->pNext->pNext = pHead->pNext;
                                }
                            }
                        }
                        else
                        {
                            for (NODE* pTemp = pHead->pNext; pTemp->pNext != pHead->pNext; pTemp = pTemp->pNext)
                            {
                                if (pTemp->pNext == p)
                                    pTemp->pNext = p->pNext;
                            }
                        }
                    }
                    else if ((p->pNext->pNext == pHead->pNext) && (!strcmp(pMax->szName, p->pNext->szName)))
                    {
                        p->pNext = pHead->pNext;
                    }
                }
            }
        }

        if (pSort->pNext == NULL)
        {
            pTemp = pMax;
            pSort->pNext = pMax;
            pMax->pNext = pSort->pNext;
        }
        else
        {
            pTemp->pNext = pMax;
            pMax->pNext = pSort->pNext;
            pTemp = pMax;
        }
    }
    pHead->pNext = pSort->pNext;

}

void sort_data(Node* ptr) {
    Node* head = ptr->Next;
    Node* tail = ptr;
    for (int i = 0; i < 10; i++) {
        if (head->Next == tail) {
        }
        if (head->data < head->Next->data) {
            Node* swap1 = head;
            Node* swap2 = head->Next;
            swap1->Next = swap2->Next;
            swap2->Next = swap1;
            tail->Next = swap2;
            tail = tail->Next;
        }
        else {
            head = head->Next;
            tail = tail->Next;
        }
    }
}