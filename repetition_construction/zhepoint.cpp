#include <stdio.h>

int main() {
    int n, i, count = 0;
    int sales[100]; // �洢ÿ���������

    // ��ȡ����
    scanf("%d", &n);

    // ��ȡÿ���������
    for(i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    // �����۵�����
    for(i = 1; i < n - 1; i++) {
        // ����Ƿ�Ϊ�۵�
        if((sales[i] > sales[i - 1] && sales[i] > sales[i + 1]) || 
           (sales[i] < sales[i - 1] && sales[i] < sales[i + 1])) {
            count++;
        }
    }

    // ����۵�����
    printf("%d\n", count);

    return 0;
}
