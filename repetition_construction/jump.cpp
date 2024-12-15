#include<stdio.h>
int main(){
    int state=0,score=0,addup=0;
    char input;
    do{
        input=getchar();
        getchar();
        if(input=='0'){
            break;
        }
        else if(input=='1'){
            score+=1;
            state=0;        
        }
        else{
            if(state==0){
                addup=2;
                state=1;
            }
            else if(state==1){
                addup+=2;
            }
            score+=addup;
        }
    }while(input!='\n');
    printf("%d",score);
    return 0;
}