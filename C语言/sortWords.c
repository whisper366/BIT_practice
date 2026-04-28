#include<stdio.h>
#include<string.h>
#define MAX 20
void swap(const char*str1,const char *str2){
    char temp[100];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}

int main(){
    char str[5][MAX];
    char temp[100];
    for(int i=0;i<5;i++){
        scanf("%s",str[i]);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4-i;j++){
            if(strcmp(str[j],str[j+1])<0){
                swap(str[j],str[j+1]);
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%s\n",str[i]);
    }
    return 0;
}