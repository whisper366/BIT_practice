//输入格式：输入两个字符串
//输出格式：
//输出第二个串在第一个串中出现的次数。
//如果没有，输出 No

#include<stdio.h>
#include<string.h>
int main(){
	char str1[1000],str2[1000];
	fgets(str1,sizeof(str1),stdin);
	fgets(str2,sizeof(str2),stdin);
	str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
	int count=0;
	char *pos=strstr(str1,str2);
	while(pos!=NULL){
		count++;
		pos=strstr(pos+strlen(str2),str2);
	}
	if(count>0) printf("%d\n",count);
	else printf("No\n");
	return 0;
}