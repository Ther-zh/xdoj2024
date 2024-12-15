#include<stdio.h>
int arr[30];
int main(){
    int n;
    scanf("%d",&n);
    int tem=0,maxgap=0,gap=0;
    for(int i=0;i<n;i++){
        scanf("%d",&tem);
        arr[i]=tem;
        if (i>0){
            gap=tem>arr[i-1]?tem-arr[i-1]:arr[i-1]-tem;
        }
        if(gap>maxgap){
            maxgap=gap;
        }
    }
    printf("%d",maxgap);
    return 0;
}