#include <stdio.h>

int main() {
    int S, A, tax, T;

    // ����˰ǰ����
    scanf("%d", &S);

    // ����Ӧ��˰���ö� A
    A = S - 3500;

    // ���ݲ�ͬ��˰���������˰��
    if(A<=0){
        tax=0;
    }
    else if (A <= 1500) {
        tax = A * 3 / 100;
    } else if (A <= 4500) {
        tax = 1500 * 3 / 100 + (A - 1500) * 10 / 100;
    } else if (A <= 9000) {
        tax = 1500 * 3 / 100 + 3000 * 10 / 100 + (A - 4500) * 20 / 100;
    } else if (A <= 35000) {
        tax = 1500 * 3 / 100 + 3000 * 10 / 100 + 4500 * 20 / 100 + (A - 9000) * 25 / 100;
    } else {
        tax = 1500 * 3 / 100 + 3000 * 10 / 100 + 4500 * 20 / 100 + 26000 * 25 / 100 + (A - 35000) * 30 / 100;
    }

    // ����˰���� T
    T = S - tax;

    // ���˰����
    printf("%d\n", T);

    return 0;
}