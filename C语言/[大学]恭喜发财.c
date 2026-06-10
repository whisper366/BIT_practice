/*第 1 行:	一个整数 N（2 <= N <= 10)
第 2..N+1 行:	每行是一个人名，每个名字不超过 14 个字符
第 N+2..结束:	N 组按照以下规则组织的数据：
组中的第一行为送出压岁钱的人名。
第二行包括两个数字，第一个是该人有多少钱，第二个是它要把钱发给几个人的小孩，用 NGi 表示(0 ≤ NGi ≤ N-1).
如果 NGi 为非零，则下面的 NGi 行会列出接受压岁钱的人的名字。
输出：N 行，每行上是一个人名与它收到和送出的压岁钱之差额，这两项之间有一个空格。
    这 N 行的顺序应该和输入中第 2~N+1 行的顺序相同。*/
#include<stdio.h>
#include <stdio.h> 
#include <string.h> 
#include<stdlib.h>

typedef struct
{
    char name[14];
    int value;
}Person;

int find_p(Person *p,int N,char *str){
    for (int i=0;i<N;i++){
        if(strcmp(p[i].name,str)==0)
        {
            return i;
            break;
        } 
    }
    return -1;
}

int main( ){
    int N;
    scanf("%d",&N);
    Person *p=malloc(N*sizeof(Person));
    //读取人名，并把各自金额初始化成0
    for(int i=0;i<N;i++){
        scanf("%s",p[i].name);
        p[i].value=0;
    }
    
    for(int j=0;j<N;j++){
        char giver[14];
        scanf("%s",giver);
        int total,num;
        scanf("%d %d",&total,&num);
        //确定施与者的index和n>0情况下获得者的index
        int giver_index=find_p(p,N,giver);
        if(num>0){
            int give=total/num;
            p[giver_index].value-=give*num;
            for(int i=0;i<num;i++){
                char friend[14];
                scanf("%s",friend);
                int rec_index=find_p(p,N,friend);
                p[rec_index].value+=give;
            }
        }
    }
    for(int i=0;i<N;i++){
        printf("%s %d\n",p[i].name,p[i].value);
    }
    free(p);
    return 0;
}