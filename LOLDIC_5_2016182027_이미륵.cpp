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

typedef struct Champion_DL
{
    char cPosition[16];
    char szName[16];
    int iHp;
    int iAtt;
    int iShield;
    Champion_DL* pNext;
    Champion_DL* pPrev;
}NODE_DL;

NODE_SL* pHead_SL = (NODE_SL*)malloc(sizeof(NODE_SL));
NODE_SL* pTail_SL = (NODE_SL*)malloc(sizeof(NODE_SL));
NODE_SL* pSort_SL = (NODE_SL*)malloc(sizeof(NODE_SL));
NODE_DL* pHead_DL = (NODE_DL*)malloc(sizeof(NODE_DL));

void PrintAll_SL();
void PrintAll_DL();
void SortByName_SL();
void SortByName_DL();
void FindTarget_SL();
void FindTarget_DL();
void List_SL(NODE_SL* p)
{
    if (pHead_SL->pNext == NULL)
    {
        pHead_SL->pNext = p;
        pTail_SL->pNext = p;
        p->pNext = p;
    }
    else
    {
        p->pNext = pHead_SL->pNext;
        pTail_SL->pNext->pNext = p;
        pTail_SL->pNext = p;
    }
}
void List_DL(NODE_DL* p)
{
    if (pHead_DL->pNext == NULL)
    {
        pHead_DL->pNext = p;
        p->pNext = p;
        p->pPrev = p;
    }
    else
    {
        p->pNext = pHead_DL->pNext;
        p->pPrev = pHead_DL->pNext->pPrev;
        p->pPrev->pNext = p;
        pHead_DL->pNext->pPrev = p;
    }
}
void Array2LinkedList()
{
    pHead_SL->pNext = NULL;
    pTail_SL->pNext = NULL;
    pHead_DL->pNext = NULL;
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

        NODE_DL* pTemp_DL = (NODE_DL*)malloc(sizeof(NODE_DL));
        strcpy(pTemp_DL->cPosition, cTempPosition);
        strcpy(pTemp_DL->szName, szTempName);
        pTemp_DL->iHp = iTempHp;
        pTemp_DL->iAtt = iTempAtt;
        pTemp_DL->iShield = iTempShield;

        if (pHead_DL->pNext == NULL)
        {
            pHead_DL->pNext = pTemp_DL;
            pTemp_DL->pNext = pTemp_DL;
            pTemp_DL->pPrev = pTemp_DL;
        }                  
        else
        {
            pTemp_DL->pNext = pHead_DL->pNext;
            pTemp_DL->pPrev = pHead_DL->pNext->pPrev;
            pTemp_DL->pPrev->pNext = pTemp_DL;
            pHead_DL->pNext->pPrev = pTemp_DL;
        }
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
        printf("1.PrintAll_SL  2.PrintAll_DL  3.SortByName_SL  4.SortByName_DL  5.FindTarget_SL  6.FindTarget_DL  7.Exit\n");
        scanf_s("%d", &iSelect);
        while (getchar() != '\n');

        switch (iSelect)
        {
        case 1:
            cStart = clock();
            PrintAll_SL();
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 2:
            cStart = clock();
            PrintAll_DL();
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 3:
            cStart = clock();
            SortByName_SL();
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 4:
            cStart = clock();
            SortByName_DL();
            cEnd = clock();
            result = (double)(cEnd - cStart);
            printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
            break;
        case 5:
            FindTarget_SL();
            break;
        case 6:
            FindTarget_DL();
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
    free(pHead_DL);
    return 0;
}
void PrintAll_SL()
{
    for (NODE_SL* p = pHead_SL->pNext; p->pNext != pHead_SL->pNext; p = p->pNext)
    {
        if (p->iHp > 0)
            printf("%s %s %d %d %d\n", p->cPosition, p->szName, p->iHp, p->iAtt, p->iShield);
        if(p->pNext->pNext == pHead_SL->pNext)
            printf("%s %s %d %d %d\n", p->pNext->cPosition, p->pNext->szName, p->pNext->iHp, p->pNext->iAtt, p->pNext->iShield);
    }
}
void PrintAll_DL()
{
    for (NODE_DL* p = pHead_DL; p != pHead_DL->pNext->pPrev;)
    {
        p = p->pNext;
        if (p->iHp > 0)
            printf("%s %s %d %d %d\n", p->cPosition, p->szName, p->iHp, p->iAtt, p->iShield);
    }
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
            if (strcmp(pMax->szName,p->pNext->szName) < 0)
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
void SortByName_DL()
{
    NODE_DL* pMax;
    NODE_DL Temp;
    pMax = pHead_DL->pNext;
    for (NODE_DL* p = pHead_DL; p != pHead_DL->pNext->pPrev;)
    {
        p = p->pNext;
        if (strcmp(pMax->szName, p->pNext->szName) < 0)
            pMax = p->pNext;
    }
    for (NODE_DL* p = pHead_DL; p != pHead_DL->pNext->pPrev;)
    {
        p = p->pNext;
        if (!strcmp(pMax->szName, p->szName))
        {
            strcpy(Temp.cPosition, p->cPosition);
            strcpy(p->cPosition, pHead_DL->pNext->cPosition);
            strcpy(pHead_DL->pNext->cPosition, Temp.cPosition);
            strcpy(Temp.szName, p->szName);
            strcpy(p->szName, pHead_DL->pNext->szName);
            strcpy(pHead_DL->pNext->szName, Temp.szName);

            Temp.iHp = p->iHp;
            p->iHp = pHead_DL->pNext->iHp;
            pHead_DL->pNext->iHp = Temp.iHp;
            Temp.iAtt = p->iAtt;
            p->iAtt = pHead_DL->pNext->iAtt;
            pHead_DL->pNext->iAtt = Temp.iAtt;
            Temp.iShield = p->iShield;
            p->iShield = pHead_DL->pNext->iShield;
            pHead_DL->pNext->iShield = Temp.iShield;
        }
    }
    for (NODE_DL* p = pHead_DL->pNext; p != pHead_DL->pNext->pPrev;)
    {
        p = p->pNext;
        if (p->pNext == pHead_DL->pNext)
            break;
        if (p->pNext == pHead_DL->pNext)
        {
            if (strcmp(p->szName, p->pNext->szName) < 0)
            {
                p->pPrev->pNext = p->pNext;
                p->pNext->pNext->pPrev = p;
                p->pNext->pPrev = p->pPrev;
                p->pNext = p->pNext->pNext;
                p->pPrev->pNext->pNext = p;
                p->pPrev = p->pPrev->pNext;
                p = p->pPrev;
            }
        }
        else
        {
            if (strcmp(p->szName, p->pNext->szName) < 0) {
                p->pPrev->pNext = p->pNext;
                p->pNext->pNext->pPrev = p;
                p->pNext->pPrev = p->pPrev;
                p->pNext = p->pNext->pNext;
                p->pPrev->pNext->pNext = p;
                p->pPrev = p->pPrev->pNext;
                p = p->pPrev;
            }
            NODE_DL* h = p->pPrev;
            while (1)
            {
                if (h->szName == pHead_DL->pNext->szName)
                    break;
                if (strcmp(h->szName, h->pNext->szName) < 0) {
                    h->pPrev->pNext = h->pNext;
                    h->pNext->pNext->pPrev = h;
                    h->pNext->pPrev = h->pPrev;
                    h->pNext = h->pNext->pNext;
                    h->pPrev->pNext->pNext = h;
                    h->pPrev = h->pPrev->pNext;
                    h = h->pPrev->pPrev;
                }
                else
                    break;
            }
        }
    }
}
void FindTarget_SL()
{
    clock_t cStart, cEnd;
    double result;

    bool bSuccess = false;
    char szSearchName[32] = "";
    printf("검색할 챔피언의 이름: ");
    gets_s(szSearchName);

    cStart = clock();
    for (NODE_SL* p = pHead_SL->pNext; p->pNext != pHead_SL->pNext; p = p->pNext)
    {
        if (!strcmp(p->szName, szSearchName))
        {
            printf("%s %s %d %d %d\n", p->cPosition, p->szName, p->iHp, p->iAtt, p->iShield);
            bSuccess = true;
        }
        if (!strcmp(p->pNext->szName, szSearchName))
        {
            printf("%s %s %d %d %d\n", p->pNext->cPosition, p->pNext->szName, p->pNext->iHp, p->pNext->iAtt, p->pNext->iShield);
            bSuccess = true;
        }
    }
    if (!bSuccess)
        printf("찾으시는 챔피언이 없습니다.\n");
    cEnd = clock();

    result = (double)(cEnd - cStart);
    printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
}
void FindTarget_DL()
{
    clock_t cStart, cEnd;
    double result;
    bool bSuccess = false;
    char szSearchName[32] = "";
    printf("검색할 챔피언의 이름: ");
    gets_s(szSearchName);

    cStart = clock();
    for (NODE_DL* p = pHead_DL; p != pHead_DL->pNext->pPrev;)
    {
        p = p->pNext;
        if (!strcmp(p->szName, szSearchName))
        {
            printf("%s %s %d %d %d\n", p->cPosition, p->szName, p->iHp, p->iAtt, p->iShield);
            bSuccess = true;
        }
    }
    if (!bSuccess)
        printf("찾으시는 챔피언이 없습니다.\n");
    cEnd = clock();

    result = (double)(cEnd - cStart);
    printf("수행시간: %f초\n", result / CLOCKS_PER_SEC);
}