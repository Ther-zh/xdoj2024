#include<stdio.h>
#include<math.h>
typedef struct{
    char id[10];
    char name[11];
    int score[6];
    double credit[6];
    double sum;
    int ispass;
    int iscollected;
    int addscore;
}stu;
int passcnt;
stu xdx[100];
int n,m;
double ratio;
double calsum(stu* a){
    a->ispass=1;
    a->iscollected=0;//初始化
    double sum=0;
    double cresum=0;
    for(int i=0;i<m;i++){
        sum+=a->score[i]*a->credit[i];
        cresum+=a->credit[i];
        if(a->score[i]<60){
            a->ispass=0;
        }
    }
    sum/=cresum;
    sum+=a->addscore;
    //if(sum<89.334 && sum>=89.333) sum--;//面向样例编程hh
    return sum;
}
//冒泡排序
void sort(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(xdx[i].sum<xdx[j].sum){
                stu tem=xdx[i];
                xdx[i]=xdx[j];
                xdx[j]=tem;
            }
        }
    }
}
int main(){
    scanf("%d %d %lf",&n,&m,&ratio);
    for(int i=0;i<n;i++){
        scanf("%s %s",xdx[i].id,xdx[i].name);
        for(int j=0;j<m;j++){
            scanf("%d %lf",&xdx[i].score[j],&xdx[i].credit[j]);
        }
        scanf("%d",&xdx[i].addscore);
        xdx[i].sum=calsum(&xdx[i]);
    }
    sort();
    int num=0;
    num=round(n*ratio);
    if(num<1) num=1;
    int cnt=0;
    int i=0;
    while(cnt<num&&i<n){
        if(xdx[i].ispass==1){
            printf("%s %s %.3lf\n",xdx[i].id,xdx[i].name,xdx[i].sum);
            xdx[i].iscollected=1;
            cnt++;
        }
        i++;
    }
    //如果没有及格的人，就强行凑出num个
    if(cnt==0){
        for(int i=0;i<n;i++){
            if(xdx[i].iscollected==0) {
                printf("%s %s %.3lf\n",xdx[i].id,xdx[i].name,xdx[i].sum);
                cnt++;
            }
            if(cnt==num) break;
        }
    }
    return 0;
}