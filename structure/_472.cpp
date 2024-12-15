#include <stdio.h>
#include <string.h>

struct medalCountry
{
    int iPlace;
    char sName[3];
    int iMedalNum[3];
};

enum medalType
{
    GOLDMEDAL,
    SILVERMEDAL,
    BRONZEMEDAL
};

void AdjustSortTable(int aSortTable[], struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType)
{
    int i, j, temp;
    struct medalCountry tempCountry;
    // 从当前位置开始，向上比较并交换，直到找到正确的位置
    for (i = iNo; i > 0; i--)
    {
        if (aMedalCountry[aSortTable[i]].iMedalNum[GOLDMEDAL] > aMedalCountry[aSortTable[i - 1]].iMedalNum[GOLDMEDAL])
        {
            // 交换排序表中的位置
            temp = aSortTable[i];
            aSortTable[i] = aSortTable[i - 1];
            aSortTable[i - 1] = temp;
        }
        else if (aMedalCountry[aSortTable[i]].iMedalNum[GOLDMEDAL] == aMedalCountry[aSortTable[i - 1]].iMedalNum[GOLDMEDAL])
        {
            if (aMedalCountry[aSortTable[i]].iMedalNum[SILVERMEDAL] > aMedalCountry[aSortTable[i - 1]].iMedalNum[SILVERMEDAL])
            {
                // 交换排序表中的位置
                temp = aSortTable[i];
                aSortTable[i] = aSortTable[i - 1];
                aSortTable[i - 1] = temp;
            }
            else if (aMedalCountry[aSortTable[i]].iMedalNum[SILVERMEDAL] == aMedalCountry[aSortTable[i - 1]].iMedalNum[SILVERMEDAL])
            {
                if (aMedalCountry[aSortTable[i]].iMedalNum[BRONZEMEDAL] > aMedalCountry[aSortTable[i - 1]].iMedalNum[BRONZEMEDAL])
                {
                    // 交换排序表中的位置
                    temp = aSortTable[i];
                    aSortTable[i] = aSortTable[i - 1];
                    aSortTable[i - 1] = temp;
                }
                else if (aMedalCountry[aSortTable[i]].iMedalNum[BRONZEMEDAL] == aMedalCountry[aSortTable[i - 1]].iMedalNum[BRONZEMEDAL])
                {
                    // 比较代表队代号的字母顺序
                    if (strcmp(aMedalCountry[aSortTable[i]].sName, aMedalCountry[aSortTable[i - 1]].sName) < 0)
                    {
                        // 交换排序表中的位置
                        temp = aSortTable[i];
                        aSortTable[i] = aSortTable[i - 1];
                        aSortTable[i - 1] = temp;
                    }
                    else
                    {
                        break; // 如果当前代表队的代号小于前一个代表队，则停止比较
                    }
                }
                else
                {
                    break; // 如果当前代表队的铜牌数少于前一个代表队，则停止比较
                }
            }
            else
            {
                break; // 如果当前代表队的银牌数少于前一个代表队，则停止比较
            }
        }
        else
        {
            break; // 如果当前代表队的金牌数少于前一个代表队，则停止比较
        }
    }
}

int main(void)
{
    int n, i, j, counter = 0;
    struct medalCountry aMedalCountry[206] = {0};
    struct medalCountry *pSMC;
    int aSortTable[206];
    char sNameTmp[3];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        // Gold Medal0
        scanf("%s", sNameTmp);
        for (j = 0; j < counter; j++)
        {
            if (!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
                break;
            }
        }
        if (j == counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
            aSortTable[j] = j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
        }

        // Silver Medal
        scanf("%s", sNameTmp);
        for (j = 0; j < counter; j++)
        {
            if (!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
                break;
            }
        }
        if (j == counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
            aSortTable[j] = j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
        }

        // Bronze Medal
        scanf("%s", sNameTmp);
        for (j = 0; j < counter; j++)
        {
            if (!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
                break;
            }
        }
        if (j == counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
            aSortTable[j] = j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
        }
    }

    for (i = 0; i < counter; i++)
    {
        aMedalCountry[aSortTable[i]].iPlace = i;
        pSMC = aMedalCountry + aSortTable[i];
        printf("%3d %3s %3d %3d %3d\n", pSMC->iPlace + 1, pSMC->sName, pSMC->iMedalNum[GOLDMEDAL], pSMC->iMedalNum[SILVERMEDAL], pSMC->iMedalNum[BRONZEMEDAL]);
    }

    return 0;
}
