#include <stdio.h>

int main() {
    int n, i;
    int count[6] = {0}; // 用于统计各级天气的天数
    int pm25;
    float sum = 0.0; // 用于计算PM2.5的总和

    // 读取天数
    scanf("%d", &n);

    // 读取每天的PM2.5值并统计
    for(i = 0; i < n; i++) {
        scanf("%d", &pm25);
        sum += pm25; // 累加PM2.5值

        // 根据PM2.5值判断天气等级并增加相应计数
        if(pm25 <= 50) count[0]++;
        else if(pm25 <= 100) count[1]++;
        else if(pm25 <= 150) count[2]++;
        else if(pm25 <= 200) count[3]++;
        else if(pm25 <= 300) count[4]++;
        else count[5]++;
    }

    // 计算并输出PM2.5平均值
    printf("%.2f\n", sum / n);

    // 输出各级天气的天数
    for(i = 0; i < 6; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}
