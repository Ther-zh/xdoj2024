#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(b==1||b==3||b==5||b==7||b==8||b==10||b==12){
        printf("31");
    }
    else{
        if(b==2){
            if(a%400==0||(a%4==0&&a%100!=0)){
                printf("29");
            }
            else{
                printf("28");
            }
        }
        else{
            printf("30");
        }
    }
    return 0;
}