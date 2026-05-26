//H7小蜜蜂：统计a->b的路线个数
//结果超出longlongint,所以转化成字符串
#include <stdio.h>
#include <string.h>
#define MAXD 200  
// 大整数加法：将 a 和 b 相加，结果存入 sum
// 数组低位存个位，高位存高位，每个元素 0~9
void add(int *a, int *b, int *sum) {
    int carry = 0;
    for (int i = 0; i < MAXD; i++) {
        int t = a[i] + b[i] + carry;
        sum[i] = t % 10;
        carry = t / 10;
    }
}

// 复制大整数：将 src 复制到 dst
void copy(int *dst, int *src) {
    for (int i = 0; i < MAXD; i++) dst[i] = src[i];
}

// 输出大整数（从最高非零位开始）
void print(int *num) {
    int i = MAXD - 1;
    while (i > 0 && num[i] == 0) i--;
    for (; i >= 0; i--) printf("%d", num[i]);
    printf("\n");
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int n = b - a;
    if (n == 0) {
        printf("1\n");
        return 0;
    }

    // f[1] = 1, f[2] = 2
    int f1[MAXD] = {0}, f2[MAXD] = {0}, fn[MAXD] = {0};
    f1[0] = 1;   
    f2[0] = 2;   
    if (n == 1) {
        print(f1);
    } else if (n == 2) {
        print(f2);
    } else {
        for (int i = 3; i <= n; i++) {
            add(f1, f2, fn);   // fn = f1 + f2
            copy(f1, f2);      // f1 = f2
            copy(f2, fn);      // f2 = fn
        }
        print(f2);
    }
    return 0;
}