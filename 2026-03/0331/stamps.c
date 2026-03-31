//输入格式:四种邮票的面值
//输出格式：用这四种面值(最多使用5张）组成的邮资最大的从1开始的一个连续的区间
#include <stdio.h>
#include <string.h>

#define MAX 1000  // 足够大的空间

int main() {
    int stamp[4];
    int dp[MAX];
    
    // 输入4种邮票
    for (int i = 0; i < 4; i++) {
        scanf("%d", &stamp[i]);
    }

    // 初始化：dp[x] = 凑出x钱数需要的最少邮票数
    // 先全部设为很大的数（表示凑不出）
    for (int i = 0; i < MAX; i++) {
        dp[i] = 100;
    }
    dp[0] = 0;  // 0邮资需要0张

    // 动态规划计算
    for (int i = 1; i < MAX; i++) {  // 遍历所有邮资
        for (int j = 0; j < 4; j++) { // 遍历4种邮票
            //要凑 i 元：
            //试贴一张邮票 stamp [j]
            //剩下的钱是 i - stamp[j]若能凑出来，dp[i] = dp[剩下的钱] + 1（这一张）
            if (stamp[j] <= i && dp[i - stamp[j]] + 1 < dp[i]) {
                dp[i] = dp[i - stamp[j]] + 1;
            }
        }
    }

    // 找从1开始连续最大的数
    int ans = 0;
    for (int i = 1; i < MAX; i++) {
        if (dp[i] <= 5) {  // 不超过5张就能凑出
            ans = i;
        } else {
            break;  // 断了，停止
        }
    }

    printf("The max is %d.\n", ans);
    return 0;
}