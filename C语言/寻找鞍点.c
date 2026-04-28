#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    int found = 0;
    for (int i = 0; i < n && !found; i++) {
        // 找出第 i 行的最大值及对应的列索引（只保留第一个最大值）
        int row_max = a[i][0];
        int col_of_max = 0;
        for (int j = 1; j < m; j++) {
            if (a[i][j] > row_max) {
                row_max = a[i][j];
                col_of_max = j;
            }
        }
        // 检查该最大值是否也是其所在列的最小值
        int is_saddle = 1;
        for (int k = 0; k < n; k++) {
            if (a[k][col_of_max] < row_max) {
                is_saddle = 0;
                break;
            }
        }
        if (is_saddle) {
            printf("Point:a[%d][%d]==%d\n", i, col_of_max, row_max);
            found = 1;
        }
    }

    if (!found)
        printf("No Point\n");

    return 0;
}