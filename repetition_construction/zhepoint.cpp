#include <stdio.h>

int main() {
    int n, i, count = 0;
    int sales[100]; // 存储每天的销售量

    // 读取天数
    scanf("%d", &n);

    // 读取每天的销售量
    for(i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    // 计算折点数量
    for(i = 1; i < n - 1; i++) {
        // 检查是否为折点
        if((sales[i] > sales[i - 1] && sales[i] > sales[i + 1]) || 
           (sales[i] < sales[i - 1] && sales[i] < sales[i + 1])) {
            count++;
        }
    }

    // 输出折点数量
    printf("%d\n", count);

    return 0;
}
