#include<stdio.h>
#include<string.h>
int main(){
    char code[50]={0};
    int book[4]={0};//0大写，1小写，2数字，3others
    scanf("%s",code);
    int len=strlen(code);
    int score=0;
    if(len==0){
        score+=0;
    }
    else {
        score+=1;
        if(len>8){
            score+=1;
        }
    }
    int sum=0;
    for(int i=0;code[i]!='\0';i++){
        int kind;
        if(code[i]>='A'&&code[i]<='Z'){
            kind=0;
        }
        else if(code[i]>='a'&&code[i]<='z'){
            kind=1;
        }
        else if(code[i]>='0'&&code[i]<='9'){
            kind=2;
        }
        else{
            kind=3;
        }
        if(book[kind]==0){
            sum++;
        }
        book[kind]++;
    }
    switch (sum){
    case 2:
        score+=1;
        break;
    case 3:
        score+=2;
        break;
    case 4:
        score+=3;
        break;
    default:
        break;
    }
    printf("%d",score);
    return 0;
}