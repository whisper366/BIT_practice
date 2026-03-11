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