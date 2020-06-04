#include <stdio.h>
#include <string>
#include <time.h>

typedef struct Champion_SL
{
    char cPosition[16];
    char szName[16];
    int iHp;
    int iAtt;
    int iShield;
    Champion_SL* pNext;
}NODE_SL;

typedef struct Champion_BT
{
    char cPosition[16];
    char szName[16];
    int iHp;
    int iAtt;
    int iShield;
    Champion_BT* pLeft;
    Champion_BT* pRight;
    Champion_BT* pUp;
}NODE_BT;

NODE_SL* pHead_SL = (NODE_SL*)malloc(sizeof(NODE_SL));
NODE_SL* pTail_SL = (NODE_SL*)malloc(sizeof(NODE_SL));
NODE_SL* pSort_SL = (NODE_SL*)malloc(sizeof(NODE_SL));
NODE_BT* pRoot_BT = (NODE_BT*)malloc(sizeof(NODE_BT));

void SortByName_SL();
void SearchByName_BT();
void Insert_BT();
void Delete_BT(NODE_BT*);
void PrintAll_BT(NODE_BT*);
void SortByName_BT(NODE_BT*);

void ArrayTree(NODE_BT* Data, NODE_BT* Tree)
{
    if (strcmp(Data->szName, Tree->szName) > 0)
    {
        if (Tree->pRight == NULL)
        {
            Data->pLeft = NULL;
            Data->pRight = NULL;
            Tree->pRight = Data;
            Data->pUp = Tree;
        }
        ArrayTree(Data, Tree->pRight);
    }
    else if (strcmp(Data->szName, Tree->szName) < 0)
    {
        if (Tree->pLeft == NULL)
        {
            Data->pLeft = NULL;
            Data->pRight = NULL;
            Tree->pLeft = Data;
            Data->pUp = Tree;
        }
        ArrayTree(Data, Tree->pLeft);
    }
}
void Array2LinkedList()
{
    pHead_SL->pNext = NULL;
    pTail_SL->pNext = NULL;
    pRoot_BT = NULL;
    FILE* fp;
    char szTempName[16];
    char cTempPosition[16];
    int iTempHp, iTempAtt, iTempShield;

    fp = fopen("..//LOLDic.txt", "r");
    while (!feof(fp))
    {
        NODE_SL* pTemp_SL = (NODE_SL*)malloc(sizeof(NODE_SL));
        fflush(stdin);
        fscanf(fp, "%s %s %d %d %d\n", cTempPosition, szTempName, &iTempHp, &iTempAtt, &iTempShield);

        strcpy(pTemp_SL->cPosition, cTempPosition);
        strcpy(pTemp_SL->szName, szTempName);
        pTemp_SL->iHp = iTempHp;
        pTemp_SL->iAtt = iTempAtt;
        pTemp_SL->iShield = iTempShield;

        if (pHead_SL->pNext == NULL)
        {
            pHead_SL->pNext = pTemp_SL;
            pTail_SL->pNext = pTemp_SL;
            pTemp_SL->pNext = pTemp_SL;
        }
        else
        {
            pTemp_SL->pNext = pHead_SL->pNext;
            pTail_SL->pNext->pNext = pTemp_SL;
            pTail_SL->pNext = pTemp_SL;
        }

        NODE_BT* pTemp_BT = (NODE_BT*)malloc(sizeof(NODE_BT));
        strcpy(pTemp_BT->cPosition, cTempPosition);
        strcpy(pTemp_BT->szName, szTempName);
        pTemp_BT->iHp = iTempHp;
        pTemp_BT->iAtt = iTempAtt;
        pTemp_BT->iShield = iTempShield;
        
        if (pRoot_BT == NULL)
        {
            pTemp_BT->pLeft = NULL;
            pTemp_BT->pRight = NULL;
            pRoot_BT = pTemp_BT;
        }
        else
            ArrayTree(pTemp_BT, pRoot_BT);

    }
    fclose(fp);
}

int main()
{
    clock_t cStart, cEnd;
    bool bExit = false;
    double result;
    Array2LinkedList();
    while (!bExit)
    {
        int iSelect = 0;
        system("cls");
        printf("1.SortByName_SL  2.SearchByName_BT  3.Insert_BT  4.Delete_BT  5.PrintAll_BT  6.SortByName_BT  7.Exit\n");
        scanf_s("%d", &iSelect);
        while (getchar() != '\n');

        switch (iSelect)
        {
        case 1:
            cStart = clock();
            SortByName_SL();
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 2:
            SearchByName_BT();
            break;
        case 3:
            cStart = clock();
            Insert_BT();
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 4:
            Delete_BT(pRoot_BT);
            break;
        case 5:
            cStart = clock();
            PrintAll_BT(pRoot_BT);
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 6:
            cStart = clock();
            SortByName_BT(pRoot_BT);
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 7:
            bExit = true;
            break;
        default:
            printf("다시 입력해주세요\n");
            break;
        }
        system("pause");
    }

    free(pHead_SL);
    free(pRoot_BT);
    return 0;
}

void SortByName_SL()
{
    NODE_SL* pMax;
    NODE_SL* pTemp = NULL;
    pSort_SL->pNext = NULL;
    while (pHead_SL->pNext != NULL)
    {
        pMax = pHead_SL->pNext;
        for (NODE_SL* p = pHead_SL->pNext; p->pNext != pHead_SL->pNext; p = p->pNext)
        {
            if (strcmp(pMax->szName, p->pNext->szName) < 0)
                pMax = p->pNext;
            if ((p->pNext->pNext == pHead_SL->pNext) && (strcmp(pMax->szName, p->pNext->szName) < 0))
                pMax = p->pNext;
        }
        if (pHead_SL->pNext != NULL)
        {
            if (pHead_SL->pNext->pNext == pHead_SL->pNext)
            {
                if (!strcmp(pMax->szName, pHead_SL->pNext->szName))
                {
                    pHead_SL->pNext = NULL;
                }
            }
            else
            {
                for (NODE_SL* p = pHead_SL->pNext; p->pNext != pHead_SL->pNext; p = p->pNext)
                {
                    if (!strcmp(pMax->szName, p->szName))
                    {
                        if (p == pHead_SL->pNext)
                        {
                            for (NODE_SL* pTemp = pHead_SL->pNext; pTemp->pNext != pHead_SL->pNext; pTemp = pTemp->pNext)
                            {
                                if (pTemp->pNext->pNext == pHead_SL->pNext)
                                {
                                    pHead_SL->pNext = p->pNext;
                                    pTemp->pNext->pNext = pHead_SL->pNext;
                                }
                            }
                        }
                        else
                        {
                            for (NODE_SL* pTemp = pHead_SL->pNext; pTemp->pNext != pHead_SL->pNext; pTemp = pTemp->pNext)
                            {
                                if (pTemp->pNext == p)
                                    pTemp->pNext = p->pNext;
                            }
                        }
                    }
                    else if ((p->pNext->pNext == pHead_SL->pNext) && (!strcmp(pMax->szName, p->pNext->szName)))
                    {
                        p->pNext = pHead_SL->pNext;
                    }
                }
            }
        }

        if (pSort_SL->pNext == NULL)
        {
            pTemp = pMax;
            pSort_SL->pNext = pMax;
            pMax->pNext = pSort_SL->pNext;
        }
        else
        {
            pTemp->pNext = pMax;
            pMax->pNext = pSort_SL->pNext;
            pTemp = pMax;
        }
    }
    pHead_SL->pNext = pSort_SL->pNext;
}
void SearchByName_BT()
{
    clock_t cStart, cEnd;
    double result;
    char szSearchName[16] = "";
    NODE_BT* p = pRoot_BT;

    printf("검색할 챔피언의 이름:");
    gets_s(szSearchName);

    cStart = clock();
    while (true)
    {
        if (!strcmp(szSearchName, p->szName))
        {
            printf("%s %s %d %d %d\n", p->cPosition, p->szName, p->iHp, p->iAtt, p->iShield);
            break;
        }
        else if (strcmp(szSearchName, p->szName) < 0)
        {
            if (p->pLeft == NULL) {
                printf("찾으시는 챔피언이 없습니다.\n");
                break;
            }
            else
                p = p->pLeft;
        }
        else if (strcmp(szSearchName, p->szName) > 0)
        {
            if (p->pRight == NULL) {
                printf("찾으시는 챔피언이 없습니다.\n");
                break;
            }
            else
                p = p->pRight;
        }
    }
    cEnd = clock();
    result = (double)(cEnd - cStart);
    printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
}
void Insert_BT()
{
    NODE_BT* pNew = (NODE_BT*)malloc(sizeof(NODE_BT));
    NODE_BT* p = pRoot_BT;

    printf("---추가할 챔피언의 정보---\n");
    printf("이름: ");
    gets_s(pNew->szName);
    while (true)
    {
        if (!strcmp(pNew->szName, p->szName))
        {
            printf("이미 챔피언이 존재합니다.\n");
            gets_s(pNew->szName);
        }
        else if (strcmp(pNew->szName, p->szName) < 0)
        {
            if (p->pLeft == NULL)
            {
                p->pLeft = pNew;
                pNew->pLeft = NULL;
                pNew->pRight = NULL;
                pNew->pUp = p;
                break;
            }
            else
                p = p->pLeft;
        }
        else if (strcmp(pNew->szName, p->szName) > 0)
        {
            if (p->pRight == NULL)
            {
                p->pRight = pNew;
                pNew->pLeft = NULL;
                pNew->pRight = NULL;
                pNew->pUp = p;
                break;
            }
            else
                p = p->pRight;
        }
    }
    while (true)
    {
        printf("위치(TOP, JUNGLE, MID, ADCARRY, SUPPORTER): ");
        gets_s(pNew->cPosition);
        if (!strcmp("TOP", pNew->cPosition) || !strcmp("JUNGLE", pNew->cPosition) || !strcmp("MID", pNew->cPosition) || !strcmp("ADCARRY", pNew->cPosition) || !strcmp("SUPPORTER", pNew->cPosition))
            break;
        else
            printf("TOP, JUNGLE, MID, ADCARRY, SUPPORTER 중에서 정해주세요\n");
    }
    while (true)
    {
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
        printf("공격력: ");
        scanf_s("%d", &(pNew->iAtt));
        while (getchar() != '\n');
        if (pNew->iAtt > 0)
            break;
        else
            printf("잘못입력하셨습니다. 다시입력해주세요\n");
    }
    while (true)
    {
        pNew->iShield = 0;
        printf("방어력: ");
        scanf_s("%d", &(pNew->iShield));
        while (getchar() != '\n');
        if (pNew->iShield > 0)
            break;
        else
            printf("잘못입력하셨습니다. 다시입력해주세요\n");
    }
}
void Delete_BT(NODE_BT* pTree)
{
    clock_t cStart, cEnd;
    double result;
    char szDeleteName[16] = "";
    NODE_BT* p, *Up, *Down, *T, *UT;
    p = pTree;
    Up = NULL;


    printf("삭제할 챔피언의 이름: ");
    gets_s(szDeleteName);
    
    cStart = clock();
    while ((p != NULL) && (strcmp(p->szName, szDeleteName) != 0))
    {
        Up = p;
        if (strcmp(szDeleteName, p->szName) < 0)
            p = p->pLeft;
        else
            p = p->pRight;
    }
    if (p == NULL)
    {
        printf("찾는 이름이 없습니다\n");
        return;
    }

    if (p->pLeft == NULL && p->pRight == NULL)
    {
        if (Up != NULL)
        {
            if (Up->pLeft == p)
                Up->pLeft = NULL;
            else
                Up->pRight = NULL;
        }
        else
            pTree = NULL;
    }
    else if (p->pLeft == NULL || p->pRight == NULL)
    {
        if (p->pLeft != NULL)
            Down = p->pLeft;
        else
            Down = p->pRight;
        if (Up != NULL)
        {
            if (Up->pLeft == p)
                Up->pLeft = Down;
            else
                Up->pRight = Down;
        }
        else
            pTree = Down;
    }
    else
    {
        UT = p;
        T = p->pLeft;
        while (T->pRight != NULL)
        {
            UT = T;
            T = T->pRight;
        }
        if (UT->pLeft = T)
            UT->pLeft = T->pLeft;
        else
            UT->pRight = T->pLeft;
        strcpy(p->szName, T->szName);
        p = T;
    }
    cEnd = clock();
    result = (double)(cEnd - cStart);
    printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
}
void PrintAll_BT(NODE_BT* pTree)
{
    if (pTree != NULL)
    {
        PrintAll_BT(pTree->pLeft);
        printf("%s %s %d %d %d\n", pTree->cPosition, pTree->szName, pTree->iHp, pTree->iAtt, pTree->iShield);
        PrintAll_BT(pTree->pRight);
        
    }
}
void SortByName_BT(NODE_BT* pTree)
{
    PrintAll_BT(pTree);
}