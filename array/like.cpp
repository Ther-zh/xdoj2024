#include<stdio.h>
int main(){
    int n;
    int arr[101]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int tem;
            scanf("%d",&tem);
            arr[tem]++;
        }
    }
    int max=0;
    int maxnum=0;
    for(int i=1;i<101;i++){
        if(arr[i]>=max){
            max=arr[i];
            maxnum=i;
        }
    }
    printf("%d %d",maxnum,max);
    return 0;
}