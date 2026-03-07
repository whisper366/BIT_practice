#include<stdio.h>
#include<string.h>
#define MAX 10001

int main(){
    char s[MAX];
    scanf("%s",s);

    char stack[MAX];
    int top=-1; //Init:栈为空
    for(int i=0;s[i]!='\0';i++){

        //情况一：该字符与栈顶字符相同且栈不为空-->删除
        if(top>=0&&stack[top]==s[i]){
            top--;      //栈顶指针下移一位，相当于删除栈顶元素
        }

        //情况二：该字符与栈顶字符不同或栈为空-->压入
        else{
            stack[++top]=s[i];
        }
    }

    if(top==-1){
        printf("Empty\n");
    }
    else{
        //关键！！！添加结束符
        stack[top+1]='\0';
        printf("%s\n",stack);
    }
    return 0;
}

