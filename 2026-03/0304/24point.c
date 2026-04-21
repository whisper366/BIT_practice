#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(char *a,char *b){
    int lena=strlen(a);
    int lenb=strlen(b);
    if(lena==lenb){
        return strcmp(a,b);
    }
    return lena>lenb?1:-1;
}

void add(char *a,char *b){
    
}

int main(){
    int m;
    scanf_s("%d",&m);
    while(m--){
        char nums[4][105];
        for(int i=0;i<4;i++){
            scanf_s("%s",&nums[i]);
        }
        
    }

    
}