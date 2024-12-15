#include<stdio.h>

typedef struct stack{
    int tail;
    char data[51];
}stack;

void push(stack* sta, char val){
    sta->data[sta->tail++] = val;
}

char pop(stack* sta){
    return sta->data[--sta->tail];
}

int main(){
    stack sta = {0}; // 初始化tail为0
    char a;
    while((a=getchar())!='\n'){
        if(a=='('||a==')'||a=='['||a==']'||a=='{'||a=='}'){
            push(&sta, a);
            if(sta.tail > 1){
                char last = sta.data[sta.tail-1];
                char preLast = sta.data[sta.tail-2];
                if((preLast=='{'&&last=='}')||(preLast=='['&&last==']')||(preLast=='('&&last==')')){
                    pop(&sta);
                    pop(&sta);
                }
            }
        }
    }
    if(sta.tail==0){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}
