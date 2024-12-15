#include<stdio.h>
int main(){
    char a,b,c,d,e;
    scanf("%c|%c|%c|%c|%c",&a,&b,&c,&d,&e);
    a+='a'-'A';
    b+='a'-'A';
    c+='a'-'A';
    d+='a'-'A';
    e+='a'-'A';
    printf("%c%c%c%c%c!",a,b,c,d,e);
    return 0;
}