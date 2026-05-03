#include<stdio.h>
#include<string.h>
//校验码
int check(char *id){
	long long int sum=0;
	char code[12]="10X98765432";
	int W[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	for(int i=0;i<17;i++){
		sum+=(id[i]-'0')*W[i];
	}
	int mod=sum%11;
	return code[mod];
}
//15->18
void upgrade(char *id){
	char newID[19];
	strncpy(newID,id,6);
	newID[6]='1';
	if(id[14]=='6'||id[14]=='7'||id[14]=='8'||id[14]=='9'){
		newID[7]='8';
	}
	else{
		newID[7]='9';
	}
	strncpy(newID+8,id+6,9);
	newID[17]=check(newID);
	newID[18]='\0';
	strcpy(id,newID);
}
//检验是否合法
int valid(char *id){
	if(strlen(id)==15){
		char newID[19];
		strcpy(newID,id);
		upgrade(newID);
		printf("%s\n",newID);
	}
	else if(strlen(id)==18){
		char checkNode=check(id);
		if(id[17]==checkNode) printf("Valid\n");
		else printf("Invalid\n");
	}
	else{
		printf("Invalid\n");
	}
	return 1;
}
int main(){
	int N;
	scanf("%d",&N);
	int W[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	while(N--){
		char id[19];
		scanf("%s",id);
		valid(id);
	}
	return 0;
}
