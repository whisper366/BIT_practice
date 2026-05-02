#include<stdio.h>
#include<string.h>
#define MAX 100
void swap(const char *str1,const char *str2){
	char temp[30];
	strcpy(temp,str1);
	strcpy(str1,str2);
	strcpy(str2,temp);
}
int main(){
	char s[5][MAX];
	char temp[100];
	for(int i=0;i<5;i++){
		scanf("%s",s[i]);
	}
	for(int j=0;j<4;j++){
		for(int k=0;k<4-j;k++){
			if(strcmp(s[k],s[k+1])<0) swap(s[k],s[k+1]);
		}
	}
	for(int i=0;i<5;i++){
		printf("%s\n",s[i]);
	}
	return 0;
}