#include<stdio.h>
void isfull(int num){
    int sum=0;
    for(int i=1;i<num;i++){
        if(num%i==0){
            sum+=i;
        }
    }
    if(sum==num){
        printf("%d\n",num);
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
        isfull(i);
    }
    return 0;
}