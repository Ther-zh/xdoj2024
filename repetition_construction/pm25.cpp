#include <stdio.h>

int main() {
    int n, i;
    int count[6] = {0}; // ����ͳ�Ƹ�������������
    int pm25;
    float sum = 0.0; // ���ڼ���PM2.5���ܺ�

    // ��ȡ����
    scanf("%d", &n);

    // ��ȡÿ���PM2.5ֵ��ͳ��
    for(i = 0; i < n; i++) {
        scanf("%d", &pm25);
        sum += pm25; // �ۼ�PM2.5ֵ

        // ����PM2.5ֵ�ж������ȼ���������Ӧ����
        if(pm25 <= 50) count[0]++;
        else if(pm25 <= 100) count[1]++;
        else if(pm25 <= 150) count[2]++;
        else if(pm25 <= 200) count[3]++;
        else if(pm25 <= 300) count[4]++;
        else count[5]++;
    }

    // ���㲢���PM2.5ƽ��ֵ
    printf("%.2f\n", sum / n);

    // �����������������
    for(i = 0; i < 6; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}
