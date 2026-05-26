//现在需要编写一个程序，当从键盘输入某数字在且仅在哪几行出现了，该程序可以“猜”出这个数字是几。
//输入：一串以空白符分开的数字，当输入 0 时表示输入结束。
//输出：猜到的数字
//本质上是二进制的运算
#include <stdio.h>

int main() {
    int num, result = 0;
    while (scanf("%d", &num) == 1 && num != 0) {
        result += 1 << (num - 1);  // 行号从1开始，对应2^(行号-1)
    }
    printf("%d\n", result);
    return 0;
}