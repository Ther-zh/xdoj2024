#include<stdio.h>
char blur(char c){
    if(c>='a'&&c<='z'){
        return c-('a'-'A');
    }
    else{
        return c;
    }
}
int main(){
    char c;
    char s[101]={0};
    int n;
    int sum=0;
    scanf("%c %d",&c,&n);
    scanf("%s",&s);
    if(n){
        for(int i=0;s[i]!='\0';i++){
            if(s[i]==c){
                sum++;
            }
        }
    }
    else{
        for(int i=0;s[i]!='\0';i++){
            if(blur(s[i])==blur(c)){
                sum++;
            }
        }
    }
    printf("%d",sum);
    return 0;
}