#include<stdio.h>

int main(){
    int n;
    int book[100000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tem;
        scanf("%d",&tem);
        book[tem]+=1;
    }
    for(int i=0;i<100000;i++){
        if(book[i]!=0){
            printf("%d:%d\n",i,book[i]);
        }
    }
    return 0;
}