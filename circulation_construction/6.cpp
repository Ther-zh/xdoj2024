#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (a*a+b*b==c*c){
        printf("%d",a*b);
    }
    else if(a*a==b*b+c*c){
        printf("%d",c*b);
    }
    else if(b*b==a*a+c*c){
        printf("%d",c*a);
    }
    else{
        printf("no");
    }
    return 0;
}