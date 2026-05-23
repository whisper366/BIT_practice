//判断输入的字符串是否对称
//注意fgets函数（会读取换行符并自动添加'\0')
//注意对len的计算（使用strcspn函数）
#include<stdio.h>
#include<string.h>
#define MAX 1000
int main(){
	char string[MAX];
	fgets(string,MAX,stdin);
	int ans=1;
	string[strcspn(string, "\n")] = '\0';
	int len=strlen(string);
	for(int i=0;i<len/2;i++){
		if(string[i]!=string[len-i-1]){
			ans=0;
			break;
		}
	}
	if(ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}