// 输入两个长度为3的字符串，每个串前两个字符是数字,后一个字符是字母。 
//求这两个串中的整数的和

// 输入
// 一行，两个字符串
// 输出
// 两个字符串中整数的和
#include<stdio.h>
#include<stdlib.h>
int main(){
    char s1[4],s2[4];
    scanf("%s %s",s1,s2);
    int num1,num2;
    num1=(s1[0]-'0')*10+(s1[1]-'0');
    num2=(s2[0]-'0')*10+(s2[1]-'0');

    int sum=num1+num2;
    printf("%d\n",sum);
    system("pause");
    return 0;
}