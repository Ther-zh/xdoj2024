
#include <stdio.h>

void calculateRotationMatrix(double q1, double q2, double q3, double q4, double R[3][3]) {
    // 计算旋转矩阵的每个元素
    R[0][0] = q1*q1 + q2*q2 - q3*q3 - q4*q4;
    R[0][1] = 2 * (q2*q3 - q1*q4);
    R[0][2] = 2 * (q2*q4 + q1*q3);

    R[1][0] = 2 * (q2*q3 + q1*q4);
    R[1][1] = q1*q1 - q2*q2 + q3*q3 - q4*q4;
    R[1][2] = 2 * (q2*q4 - q1*q2);

    R[2][0] = 2 * (q2*q4 - q1*q3);
    R[2][1] = 2 * (q3*q4 + q1*q2);
    R[2][2] = q1*q1 - q2*q2 - q3*q3 + q4*q4;
}

int main() {
    double q1, q2, q3, q4;
    double R[3][3];

    // 从用户那里获取输入
    scanf("%lf,%lf,%lf,%lf", &q1, &q2, &q3, &q4);

    // 计算旋转矩阵
    calculateRotationMatrix(q1, q2, q3, q4, R);

    // 输出旋转矩阵
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.6f ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}
