#include<stdio.h>
#include<string.h>
int main(){
	char s[100],t[100];
	scanf("%s",s);
	int len=strlen(s);
	int temp=0;
	for(int i=0;i<len;i++){
		int same=0;
		for(int j=0;j<len;j++){
			if(s[i]==t[j]){
				same=1;
				break;
			}
		}
		if(same==0){
			t[temp]=s[i];
			temp++;
		}
	}
	t[temp]='\0';
	printf("%s\n",t);
	return 0;
}