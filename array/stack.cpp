#include<stdio.h>
#include<string.h>
int main(){
    char sta[11]={0};
    scanf("%s",&sta);
    int result=1,sum=0;
    int i=10;
    for(int i=strlen(sta)-1;i>=0;i--){
        if(sta[i]!=sta[strlen(sta)-1-i]){
            printf("no");
            result=0;
            break;
        }
        sum+=sta[i]-'1'+1;
    }
    if(result==1){
        printf("%d",sum);
    }
    return 0;
}