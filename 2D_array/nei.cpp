#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    int n, m, t, k,i,j;
    scanf("%d %d %d %d", &n, &m, &t, &k);
    int mat[22][22];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int seg[51] = {0};

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int temp = mat[i][j];
            if (temp == k) {
                if (j != m - 1) {
                    seg[mat[i][j + 1]] = 1;
                }
                if (j != 0) {
                    seg[mat[i][j - 1]] = 1;
                }
                if (i != n - 1) {
                    seg[mat[i + 1][j]] = 1;
                }
                if (i != 0) {
                    seg[mat[i - 1][j]] = 1;
                }
            }
        }
    }
    int sum = 0;
    for (i = 0; i < 51; i++) {
        if (seg[i] == 1 && i != k) {
            sum++;
        }
    }

    printf("%d", sum);
    return 0;
}