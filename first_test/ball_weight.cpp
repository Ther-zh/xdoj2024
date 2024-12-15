#include<stdio.h>
#define Ferou 7.86
#define Aurou 19.3
#define PI 3.1415926
int main(){
    int fed,aud;
    scanf("%d %d",&fed,&aud);
    double feg,aug;
    feg=0.001*PI*fed*fed*fed/6*Ferou;
    aug=0.001*PI*aud*aud*aud/6*Aurou;
    printf("%.3f %.3f",feg,aug);
    return 0;
}