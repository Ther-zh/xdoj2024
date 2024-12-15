#include<stdio.h>
int gcd(int a,int b){
    int sma=a<b?a:b;
    int big=a>b?a:b;
    if(sma==0){
        return big;
    }
    else if(big%sma==0){
        return sma;
    }
    else{
        /*while(sma%(big-sma)!=0){
            big=sma;
            sma=sma%(big-sma);
        }
        return big-sma;*/
        return gcd(sma,big%sma);
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}