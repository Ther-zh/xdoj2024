#include<stdio.h>
int main(){
    int n,tem;
    scanf("%d",&n);
    if(n%2!=0){
        tem=n*n-2*(n/2);
    }
    else{
        tem=n*n-1-2*((n-1)/2);
    }
    for(int i=0;i<n;i++){
        printf("%d ",tem);
        tem+=2;
    }
    return 0;
}