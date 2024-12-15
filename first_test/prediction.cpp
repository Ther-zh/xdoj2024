#include<stdio.h>
int main(){
    int h,m;
    double T,t;
    scanf("%d %d",&h,&m);
    t=h+(double)m/60;
    T=4*t*t/(t+2)-20;
    printf("%.2f",T);
    return 0;
}