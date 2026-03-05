#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare_asc(void const*a,void const*b){
    return strcmp(*(const char**)a,*(const char**)b);
}
int main(){
    int N;
    scanf_s("%d",&N);
    char **words=(char**)malloc(N*sizeof(char*));
    if(words==NULL) return 1;

    for(int i=0;i<N;i++){
        words[i]=(char*)malloc(100*sizeof(char));
        if(words[i]==NULL){
            //释放内存
            for(int j=0;j<i;j++){
                free(words);
                return 1;
            }
        }
        scanf_s("%s",words[i]);
    }
    qsort(words,N,sizeof(words[0]),compare_asc);

    double score=100.0/N;
    for(int i=0;i<N;i++){
        printf("%s %.4f%%\n",words[i],score);
    }
    for(int j=0;j<N;j++){
        free(words[j]);
    }
    free(words);
    return 0;
}