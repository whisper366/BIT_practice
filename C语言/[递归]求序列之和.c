//1+1/2-1/3+1/4...... 结果保留六位小数

#include<stdio.h>
double sum(int n){
    if(n==0)return 0.000000;
    if(n==1) return 1.000000;
    double term=(n%2==0?1.0:-1.0)/n;
    return sum(n-1)+term;
}
int main(){
    int n;
    scanf("%d",&n);
    double result=sum(n);
    printf("%.6f\n",result);
    return 0;
}