/*逆波兰式，其定义是把运算符放在两个运算对象的后面。在后缀表达式中，不存在括号，也不存在优先级的差别，
	计算过程完全按照运算符出现的先后次序进行，整个计算过程仅需一遍扫描便可完成。
例如：
            3/5+6的逆波兰表达式为3 5 / 6 +
            2*(3+4)的逆波兰表达式为2 3 4 + *
输入：
            一个只包含加、减、乘、除和数字的逆波兰表达式
输出：
            该表达式的值

说明：
    题目中涉及的数据全部为整型*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 1000

int stack[MAX_STACK];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int is_operator(const char *s) {
    return (strlen(s) == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'));
}

int main() {
	char line[1024];
    // 读取一行（包括可能包含的空格和最后的换行）
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " \n");
    while ( token != NULL) {
        if (is_operator(token)) {
            int b = pop();  // 右操作数
            int a = pop();  // 左操作数
            int res;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;  
                default: exit(1);
            }
            push(res);
        } else {
            // 数字
            int num = atoi(token);
            push(num);
        }
		token=strtok(NULL," \n");
    }
    // 最终栈中只有一个结果
    printf("%d\n", pop());
    return 0;
}