//输入几组数据，遇到0为止
//对每一组数据内部从大到小排序
//再对内部排序完成的这几组数据从小到大排序并输出
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int decrease(const void*a,const void *b){
    return *(char*)b-*(char*)a;
}
int increase(const void*a,const void *b){
    int na=atoi(*(const char**)a);
    int nb=atoi(*(const char**)b);
    return na-nb;
}
int main(){
    int num[1000];
    int pos=0;
    int temp;
    while(1){
        scanf("%d",&temp);
        if(temp==0) break;
        num[pos++]=temp;
    }
    int size=pos;
    char arranged[size][12];
    for(int i=0;i<size;i++){
        char ans[12];
        sprintf(ans,"%d",num[i]);
        int len=strlen(ans);
        qsort(ans,len,sizeof(char),decrease);
        strcpy(arranged[i],ans);
    }
    char *ptr[size];
    for(int i=0;i<size;i++){
        ptr[i]=arranged[i];
    }
    qsort(ptr,size,sizeof(char*),increase);
    for(int i=0;i<size;i++){
        printf("%s\n",ptr[i]);
    }
    return 0;
}