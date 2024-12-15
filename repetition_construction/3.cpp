#include<stdio.h>
int gg(int num){
    int count=0;
    while(num!=1){
        if(num%2==0){
            num/=2;
        }
        else{
            num=num*3+1;
        }
        count++;
    }
    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",gg(n));
    return 0;
}