#include<iostream>
void swap(int* a,int* b){
    int tem=*a;
    *a=*b;
    *b=tem;
}
int arr1[100];
int arr2[100];
int arr[100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            //前奇数后偶数
            if(arr[i]%2==1&&arr[j]%2==0){
                swap(&arr[i],&arr[j]);
            }
            else{
                if(arr[i]%2==0&&arr[j]%2==1){
                    continue;
                }
                else{
                    if(arr[i]<arr[j]){
                        swap(&arr[i],&arr[j]);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}