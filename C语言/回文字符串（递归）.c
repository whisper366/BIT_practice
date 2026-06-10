/*判断输入的字符串是否回文（递归)
    注意对输入换行符的处理*/
#include<stdio.h>
#include<string.h>
int isPalin(char *str,int left,int right){
    if(left>=right) return 1;
    if(str[left]!=str[right]) return 0;
    return (isPalin(str,left+1,right-1));
}
int main(){
    char str[20];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Yes\n");
        return 0;
    }
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }
    if (len == 0) {
        printf("Yes\n");
        return 0;
    }

    if(isPalin(str,0,len-1)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}