#include<stdio.h>
int main(){
    double du,price;
    scanf("%lf",&du);
    if (du<=110){
        price=du*0.5;
    }
    else{
        if(du<210){
            price=110*0.5+(du-110)*0.55;
        }
        else{
            price=110*0.5+100*0.55+(du-210)*0.7;
        }
    }
    printf("%.2f",price);
    return 0;
}