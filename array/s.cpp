#include<stdio.h>

int main(){
    int a1, a2, n;
    scanf("%d %d %d", &a1, &a2, &n);
    int a[1001] = {0};
    a[1] = a1;
    a[2] = a2;
    int i = 3;
    while (i <= n) {
        int product = a[i - 2] * a[i - 1];
        if (product < 10) {
            a[i] = product;
            i++;
        } else {
            a[i] = product / 10;
            i++;
            if (i <= n) {
                a[i] = product % 10;
                i++;
            }
        }
    }
    for (int j = 1; j < i - 1; j++) { 
        printf("%d ", a[j]);
    }
    printf("%d", a[i - 1]);
    return 0;
}
