#include<stdio.h>
#include<string.h>
int main(){
	char s[80],t[80],u[160];
	fgets(s, 81, stdin);
    fgets(t, 81, stdin);
	int len1=strlen(s);
	int len2=strlen(t);
	int temp=0;
	for(int i=0;i<len1;i++){
		int same=0;
		for(int j=0;j<len2;j++){
			if(s[i]==t[j]){
				same=1;
				break;
			}
		}
		if(same==0){
			u[temp]=s[i];
			temp++;
		}
	}
	u[temp]='\0';
	printf("%s\n",u);
	return 0;
}
