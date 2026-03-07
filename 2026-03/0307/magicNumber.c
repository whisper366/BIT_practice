//一个数如果能表示为两个完全平方数的和则称为魔数。
//要求你在一堆数字中找出魔数，并且分别以二进制、八进制、十六进制输出这个数字。

// ->输入
// 第一行1个整数，代表m个数字（1≤m≤100）
// 接下来1行，为m个整数， Xi (1≤Xi≤1000)。
// ->输出
// 每个魔数1行，以空格间隔输出该魔数的二进制、八进制、十六进制
#include<stdio.h>
#include<math.h>
int is_magic(int x){
    int a,left;
    int limit=(int)sqrt(x);
    for(int a=1;a<=limit;a++){
        left=x-a*a;
        //该判断left正负的步骤易遗漏
        if(left<=0) continue;
        int b=(int)sqrt(left);
        if(b*b==left&&b>=1){
            return 1;
        }
    }
    return 0;
}

void print_Bin(int y){
    int start=0;
    for(int i=10;i>=0;i--){
        //按位与运算，从高到低逐位获得数字
        if(y&(1<<i)){
            putchar('1');
            start=1;
        }
        else if(start){
            putchar('0');
        }
    }
}
int main(){
    int m;
    int num[101];
    int found=0;
    //读取数据
    scanf_s("%d",&m);
    for(int i=0;i<m;i++){
        scanf_s("%d",&num[i]);
    }

    for(int i=0;i<m;i++){
        if(is_magic(num[i])){
            printf("0b");
            print_Bin(num[i]);
            printf(" 0o%o 0x%x\n",num[i],num[i]);
        }
    }
    return 0;

}
