#include<stdio.h>
void exchange(int *arr,int a ,int b){
    int tem=arr[a];
    arr[a]=arr[b];
    arr[b]=tem;
}



void sort(int * arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int maxIndex = begin;
    for (int i = begin + 1; i <= end; i++) {
        if (arr[i] < arr[maxIndex]) {
            maxIndex = i;
        }
    }
    exchange(arr, begin, maxIndex);
    sort(arr, begin + 1, end);
}
int main() {
    int arr[10] = {0}; 
    int n, i = 0;
    scanf("%d", &n); 
    while (n > 0) {
        arr[i] = n % 10;
        n /= 10; 
        i++;
    }

    sort(arr, 0, i - 1); 

    for (int j = i - 1; j >= 0; j--) { // 从大到小输出数字
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}


