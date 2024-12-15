#include<stdio.h>
#include<string.h>
int main(){
    char a[10];
    scanf("%s",&a);
    printf("%d",strlen(a));
    int max=0;
    int min=10;
    int i=0;
    while(a[i]!='\0'){
        if(a[i]-('1'-1)>max){
            max=a[i]-('1'-1);
        }
        if(a[i]-('1'-1)<min){
            min=a[i]-('1'-1);
        }
        i++;
    }
    printf(" %d %d",max,min);
    return 0;
}