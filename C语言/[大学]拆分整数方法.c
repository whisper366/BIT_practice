/*m 可表示为一些不超过 n 的整数之和，f(m,n) 为这种表示方式的数目
例如，f(5,3)=5，有 5 种表示方法：3+2，3+1+1，2+2+1，2+1+1+1，1+1+1+1+1。
请计算 f(m,n) 的值。*/
/*递归思路：
考虑加数中是否包含n:不包含n(f(m,n-1)),至少包含一个n(f(m-n),n)*/
#include<stdio.h>
int method(int m,int n){
    if(m==0)return 1;
    if(n==0)return 0;
    if(m<n)return method(m,m);
    else{
        return (method(m,n-1)+method(m-n,n));
    }
}
int main(){   
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d\n",method(m,n));
    return 0;
}