#include<stdio.h>
int main(){
    int a[4];
    int max=0;
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
        if(i==0||max<a[i]){
            max=a[i];
        }
    }
    printf("%d",max);
    return 0;

}