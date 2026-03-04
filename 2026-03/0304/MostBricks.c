#include<stdio.h>
#include<stdlib.h>
int main(){
    //读取N：砖头数量；M：集装箱体积
    int N,M;
    scanf_s("%d %d",&N,&M);
    
    //动态分配内存
    int *vol=(int *)calloc(N,sizeof(int));
    for(int i=0;i<N;i++){
        scanf_s("%d",&vol[i]);
    }
    int sum=0;
    int count=0;
    while(sum<=M){
        sum+=vol[count];
        count++;
    }
    printf("%d",count-1);
    return 0;

}