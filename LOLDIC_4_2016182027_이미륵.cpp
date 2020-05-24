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
            printf("���ĵǾ����ϴ�.\n");
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
    if(pHead != NULL)
        free(pHead);
    return 0;
}

void InitChamp(NODE* pChamp)
{
    pChamp[0] = { "����", "ž", 800, 0, 340, 176 };
    pChamp[1] = { "������", "����", 560, 273, 335, 450 };
    pChamp[2] = { "ī����", "����", 540, 480, 335, 450 };
    pChamp[3] = { "�ֽ�", "����", 536, 480, 325, 550 };
    pChamp[4] = { "������", "�̵�", 562, 400, 335, 125 };
    pChamp[5] = { "��", "����", 556, 300, 330, 550 };
    pChamp[6] = { "����", "����", 547, 310, 335, 125 };
    pChamp[7] = { "���ӽ�", "����", 800, 310, 335, 125 };
    pChamp[8] = { "ī����", "����", 575, 372, 350, 125 };
    pChamp[9] = { "����", "ž", 600, 270, 345, 125 };
    pChamp[10] = { "��Į��", "�̵�", 550, 220, 345, 125 };
    pChamp[11] = { "����", "����", 515, 231, 330, 550 };
    pChamp[12] = { "¡ũ��", "����", 581, 245, 325, 525 };
    pChamp[13] = { "����", "����", 571, 200, 345, 125 };
    pChamp[14] = { "����ũ", "����", 600, 415, 330, 150 };
    pChamp[15] = { "��Ʈ", "ž", 530, 300, 340, 500 };
    pChamp[16] = { "��ī��", "����", 580, 327, 345, 175 };
    pChamp[17] = { "����", "�̵�", 570, 317, 335, 175 };
    pChamp[18] = { "������", "ž", 572, 100, 345, 125 };
    pChamp[19] = { "Ž��ġ", "����", 800, 325, 335, 175 };
}

void Search_SL()
{
    bool bSuccess = false;
    char szSearchName[32] = "";
    printf("�˻��� è�Ǿ��� �̸�: ");
    gets_s(szSearchName);

    if (pHead->pNext != NULL)
    {
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (!strcmp(szSearchName, p->szName))
            {
                printf("-----%s�� ����-----\n", p->szName);
                printf("�̸�: %s\n", p->szName);
                printf("ü��: %d\n", p->iHp);
                printf("����: %d\n", p->iMp);
                printf("�ӵ�: %d\n", p->iSpeed);
                printf("����: %d\n", p->iRange);
                printf("��ġ: %s\n", p->cPosition);
                bSuccess = true;
            }
            if ((p->pNext->pNext == pHead->pNext) && (!strcmp(szSearchName, p->pNext->szName)))
            {
                printf("-----%s�� ����-----\n", p->pNext->szName);
                printf("�̸�: %s\n", p->pNext->szName);
                printf("ü��: %d\n", p->pNext->iHp);
                printf("����: %d\n", p->pNext->iMp);
                printf("�ӵ�: %d\n", p->pNext->iSpeed);
                printf("����: %d\n", p->pNext->iRange);
                printf("��ġ: %s\n", p->pNext->cPosition);
                bSuccess = true;
            }
        }
    }
    if (!bSuccess)
        printf("ã���ô� è�Ǿ��� �����ϴ�.\n");
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

    printf("---�߰��� è�Ǿ��� ����---\n");
    while (true)
    {
        printf("�̸�: ");
        gets_s(szFindName);
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (!strcmp(szFindName, p->szName))
            {
                printf("�̹� è�Ǿ��� �����մϴ�.\n");
                break;
            }
            else
                iGo = 1;
            if ((p->pNext->pNext == pHead->pNext) && (!strcmp(szFindName, p->pNext->szName)))
            {
                printf("�̹� è�Ǿ��� �����մϴ�.\n");
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
        printf("ü��: ");
        scanf_s("%d", &(pNew->iHp));
        while (getchar() != '\n');
        if (pNew->iHp > 0)
            break;
        else
            printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���\n");
    }
    while (true)
    {
        pNew->iMp = -1;
        printf("����: ");
        scanf_s("%d", &(pNew->iMp));
        while (getchar() != '\n');
        if (pNew->iMp >= 0)
            break;
        else
            printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���\n");
    }
    while (true)
    {
        pNew->iSpeed = 0;
        printf("�ӵ�: ");
        scanf_s("%d", &(pNew->iSpeed));
        while (getchar() != '\n');
        if (pNew->iSpeed > 0)
            break;
        else
            printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���\n");

    }
    while (true)
    {
        pNew->iRange = 0;
        printf("����: ");
        scanf_s("%d", &(pNew->iRange));
        while (getchar() != '\n');
        if (pNew->iRange > 0)
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
            strcpy_s(pNew->cPosition, cPos);
            break;
        }
        else
            printf("ž, ����, �̵�, ����, ���� �߿��� �����ּ���\n");
    }
}

void Delete_SL()
{
    bool bSuccess = false;
    char szDeleteName[32] = "";
    printf("������ è�Ǿ��� �̸�: ");
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
        printf("������� �ϴ� è�Ǿ��� �����ϴ�.\n");

}

void DeleteAll_SL()
{
    bool bSuccess = false;
    char szDeletePos[32] = "";
    printf("������ ������: ");
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
        printf("������� �ϴ� �������� �����ϴ�.\n");
 }

void PrintAll_SL()
{
    if (pHead->pNext != NULL)
    {
        for (NODE* p = pHead->pNext; p->pNext != pHead->pNext; p = p->pNext)
        {
            if (p->iHp != 0)
            {
                printf("-----%s�� ����-----\n", p->szName);
                printf("�̸�: %s\n", p->szName);
                printf("ü��: %d\n", p->iHp);
                printf("����: %d\n", p->iMp);
                printf("�ӵ�: %d\n", p->iSpeed);
                printf("����: %d\n", p->iRange);
                printf("��ġ: %s\n", p->cPosition);
            }
            if ((p->pNext->pNext == pHead->pNext) && (p->iHp != 0))
            {
                printf("-----%s�� ����-----\n", p->pNext->szName);
                printf("�̸�: %s\n", p->pNext->szName);
                printf("ü��: %d\n", p->pNext->iHp);
                printf("����: %d\n", p->pNext->iMp);
                printf("�ӵ�: %d\n", p->pNext->iSpeed);
                printf("����: %d\n", p->pNext->iRange);
                printf("��ġ: %s\n", p->pNext->cPosition);
            }
        }
        if (pHead->pNext->pNext == pHead->pNext)
        {
            printf("-----%s�� ����-----\n", pHead->pNext->szName);
            printf("�̸�: %s\n", pHead->pNext->szName);
            printf("ü��: %d\n", pHead->pNext->iHp);
            printf("����: %d\n", pHead->pNext->iMp);
            printf("�ӵ�: %d\n", pHead->pNext->iSpeed);
            printf("����: %d\n", pHead->pNext->iRange);
            printf("��ġ: %s\n", pHead->pNext->cPosition);
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
                printf("-----%s�� ����-----\n", p->szName);
                printf("�̸�: %s\n", p->szName);
                printf("ü��: %d\n", p->iHp);
                printf("����: %d\n", p->iMp);
                printf("�ӵ�: %d\n", p->iSpeed);
                printf("����: %d\n", p->iRange);
                printf("��ġ: %s\n", p->cPosition);
            }
            if ((p->pNext->pNext == pHead->pNext) && (p->pNext->iHp == iMaxHp))
            {
                printf("-----%s�� ����-----\n", p->pNext->szName);
                printf("�̸�: %s\n", p->pNext->szName);
                printf("ü��: %d\n", p->pNext->iHp);
                printf("����: %d\n", p->pNext->iMp);
                printf("�ӵ�: %d\n", p->pNext->iSpeed);
                printf("����: %d\n", p->pNext->iRange);
                printf("��ġ: %s\n", p->pNext->cPosition);
            }
        }
        if (pHead->pNext->pNext == pHead->pNext)
        {
            printf("-----%s�� ����-----\n", pHead->pNext->szName);
            printf("�̸�: %s\n", pHead->pNext->szName);
            printf("ü��: %d\n", pHead->pNext->iHp);
            printf("����: %d\n", pHead->pNext->iMp);
            printf("�ӵ�: %d\n", pHead->pNext->iSpeed);
            printf("����: %d\n", pHead->pNext->iRange);
            printf("��ġ: %s\n", pHead->pNext->cPosition);
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