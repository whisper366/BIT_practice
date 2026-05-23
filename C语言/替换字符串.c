#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char *str1,*str2,*str3;
	int len1,len2,len3;
	char temp[1002];
	//分别读取三个字符串
	if(fgets(temp,sizeof(temp),stdin)==NULL) return 1;
	temp[strcspn(temp,"\n")]='\0';
	len1=strlen(temp);
	str1=malloc(len1+1);
	strcpy(str1,temp);

	if(fgets(temp,sizeof(temp),stdin)==NULL) return 1;
	temp[strcspn(temp,"\n")]='\0';
	len2=strlen(temp);
	str2=malloc(len2+1);
	strcpy(str2,temp);

	if(fgets(temp,sizeof(temp),stdin)==NULL) return 1;
	temp[strcspn(temp,"\n")]='\0';
	len3=strlen(temp);
	str3=malloc(len3+1);
	strcpy(str3,temp);
	//str2为空字符串
	if(str2==NULL){
		printf("%s\n",str1);
		return 0;
	}

	//一般情况
	while(1){
		char *pos=strstr(str1,str2);
		if(pos==NULL) break;
		int before=pos-str1;
		int after=len1-before-len2;
		int size=before+len3+after;

		char *new=malloc(size+1);
		strncpy(new,str1,before);
		strcpy(new+before,str3);
		strcpy(new+before+len3,pos+len2);

		free(str1);
		str1=new;
		len1=size;
	}
	printf("%s\n",str1);
	free(str1);
	free(str2);
	free(str3);
	return 0;
}