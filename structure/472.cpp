#include <stdio.h>
#include <string.h>

struct medalCountry{
    int iPlace;
    char sName[3];
    int iMedalNum[3];
};

enum medalType{ GOLDMEDAL , SILVERMEDAL, BRONZEMEDAL};

// void AdjustSortTable(int aSortTable[], struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType) {
//     if(iNo==0) return;
//     medalCountry cur=aMedalCountry[aSortTable[iNo]];
//     while(1){
//         if(iNo==0) return;
//         //检查前一位的比变化的奖项优先级高的奖项，如果没有突破排行就没有变化
//         for(int i=0;i<iMedalType;i++){
//             if(aMedalCountry[aSortTable[iNo-1]].iMedalNum[i]>cur.iMedalNum[i]) return;
//         }
//         //检查当前变化奖项
//         //其他高阶奖项相同
//         if(cur.iMedalNum[iMedalType]>aMedalCountry[aSortTable[iNo-1]].iMedalNum[iMedalType]){
//             aMedalCountry[aSortTable[iNo]].iPlace--;//更新位次
//             aMedalCountry[aSortTable[iNo-1]].iPlace++;
//             //交换位次
//             int temp=aSortTable[iNo];
//             aSortTable[iNo]=aSortTable[iNo-1];
//             aSortTable[iNo-1]=temp;
//             iNo--;
//         }
//         //等于则继续向下比较
//         else if(cur.iMedalNum[iMedalType]==aMedalCountry[aSortTable[iNo-1]].iMedalNum[iMedalType]){
//             for(int i=iMedalType;i<=BRONZEMEDAL;i++){
//                 if(aMedalCountry[aSortTable[iNo-1]].iMedalNum[i]>cur.iMedalNum[i]){
//                     return;
//                 }
//                 else if(aMedalCountry[aSortTable[iNo-1]].iMedalNum[i]<cur.iMedalNum[i]){
//                     aMedalCountry[aSortTable[iNo]].iPlace--;//更新位次
//                     aMedalCountry[aSortTable[iNo-1]].iPlace++;

//                     int temp=aSortTable[iNo];
//                     aSortTable[iNo]=aSortTable[iNo-1];
//                     aSortTable[iNo-1]=temp;
//                     iNo--;
//                 }
//                 //这位相同比较下一位直到发现最后一个也相同才比较字典序
//             }
//             if(strcmp(cur.sName,aMedalCountry[aSortTable[iNo-1]].sName)>0){
//                 aMedalCountry[aSortTable[iNo]].iPlace--;//更新位次
//                 aMedalCountry[aSortTable[iNo-1]].iPlace++;
//                 int temp=aSortTable[iNo];
//                 aSortTable[iNo]=aSortTable[iNo-1];
//                 aSortTable[iNo-1]=temp;
//                 iNo--;
//             }
//             else return;
//         }
//         else return;
//     }
// }
void AdjustSortTable(int aSortTable[], struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType) {
    if(iNo == 0||iCounter<=1) return;
    struct medalCountry cur = aMedalCountry[aSortTable[iNo]];
    int i;

    while(iNo > 0) {
        struct medalCountry prev = aMedalCountry[aSortTable[iNo - 1]];
        // 检查所有奖牌类型
        for(i = 0; i <= BRONZEMEDAL; i++) {
            if(prev.iMedalNum[i] > cur.iMedalNum[i]) return; // 如果前一个国家在任意奖牌上更多，则不需要交换
            if(prev.iMedalNum[i] < cur.iMedalNum[i]) break; // 如果当前国家在某个奖牌上更多，则需要交换
        }
        // 如果所有奖牌数都相同，比较国家代号
        if(i >BRONZEMEDAL) {
            if(strcmp(cur.sName, prev.sName) > 0) break; // 如果当前国家代号字典序da?，则需要交换
            else return; // 否则不需要交换
        }

        // 交换位置
        aMedalCountry[aSortTable[iNo]].iPlace--;
        aMedalCountry[aSortTable[iNo - 1]].iPlace++;
        int temp = aSortTable[iNo];
        aSortTable[iNo] = aSortTable[iNo - 1];
        aSortTable[iNo - 1] = temp;
        iNo--;
    }
}

int main(void)
{
    int n,i,j,counter=0;
    struct medalCountry aMedalCountry[206]={0};
    struct medalCountry *pSMC;
    int aSortTable[206];
    char sNameTmp[3];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        //Gold Medal
        scanf("%s",sNameTmp);
        for(j=0; j<counter;j++)
        {
            if(!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
                break;
            }
        }
        if(j==counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
            aSortTable[j]=j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
        }

        //Silver Medal
        scanf("%s",sNameTmp);
        for(j=0; j<counter;j++)
        {
            if(!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
                break;
            }
        }
        if(j==counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
            aSortTable[j]=j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
        }

        //Bronze Medal
        scanf("%s",sNameTmp);
        for(j=0; j<counter;j++)
        {
            if(!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
                break;
            }
        }
        if(j==counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
            aSortTable[j]=j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
        }
    }

    for(i=0; i<counter; i++)
    {
        aMedalCountry[aSortTable[i]].iPlace = i;
        pSMC=aMedalCountry+aSortTable[i];
        printf("%3d %3s %3d %3d %3d\n", pSMC->iPlace+1, pSMC->sName, pSMC->iMedalNum[GOLDMEDAL], pSMC->iMedalNum[SILVERMEDAL], pSMC->iMedalNum[BRONZEMEDAL]);
    }

    return 0;
}
