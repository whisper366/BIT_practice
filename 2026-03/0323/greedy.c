//输入
//第一行，一个正整数 n，表示关卡数量。
//第二行，共 n 个整数 a_i，表示每个关卡。
// - 若 a_i>0，则表示这个关卡是营地，增加 a_i 的血量
// - 若 a_i<0，则表示这个关卡是战斗，机器猫血量代价为 a_i

// 机器猫任意时刻血量不能小于等于0
// 输出
// 仅一行，一个正整数，表示机器猫需要的初始血量。
#include<stdio.h>
#define MAX 100000
int n;
int a[MAX];
int check(int blood){
    long long b=blood;
    for(int i=0;i<n;i++){
        b+=a[i];
        if(b<=0) return 0;
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    int left=1;
    int max=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0){
            max+=-a[i];
        }
    }
    int right=max+1;
    while(left<right){
        int middle=left+(right-left)/2;
        if(check(middle)){
            right=middle;     //middle可以的话，大于他的都可以
        }
        else{
            left=middle+1;   //middle不行的话，左边拉高1，再次迭代middle的值进行尝试
        }
    }
    printf("%d\n",left);
    return 0;
}