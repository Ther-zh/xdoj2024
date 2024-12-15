#include<stdio.h>
typedef struct stack{
    int tail;
    char data[51];
}stack;
void push(stack& sta,char val){
    sta.data[sta.tail]=val;
    sta.tail++;
}
char pop(stack& sta){
    char result=sta.data[sta.tail];
    sta.tail--;
    return result;
}

int main(){
    stack sta={0};
    char arr[51]={0};
    scanf("%s",&arr);
    char *a=arr;
    while(*a!='\0'){
        if(*a=='('||*a==')'||*a=='['||*a==']'||*a=='{'||*a=='}'){
            push(sta,*a);
            if(sta.tail>1){
                if((sta.data[sta.tail-2]=='{'&&sta.data[sta.tail-1]=='}')||(sta.data[sta.tail-2]=='['&&sta.data[sta.tail-1]==']')||(sta.data[sta.tail-2]=='('&&sta.data[sta.tail-1]==')')){
                    pop(sta);
                    pop(sta);
                }
            }
        }
        a++;
    }
    if(sta.tail==0){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}

