//插入和输出（正序链表）
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
//输出：
void outlist (PNODE h){
    //初始化就跳过头，指向第一个有效节点
    PNODE p=h->next;
    while(p!=NULL){
        printf("%d\n",p->data);
        //移动至下一个节点
        p=p->next;
    }
}
//输入
void ins_list(PNODE h,int num){
    //初始化p1指向最后一个节点
    PNODE p1=h;
    while(p1->next!=NULL){
        p1=p1->next;
    }
    //分配内存！！
    PNODE p2=(PNODE)malloc(sizeof(NODE));
    p2->data=num;
    p2->next=NULL;
    //将p1指向新输入的内容
    p1->next=p2;
}
int main(){
    int num=1;
    PNODE head;

    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   scanf("%d", &num);  
        if ( num!=0 )  
            ins_list( head, num);  
    }  
    outlist( head );  
    return 0;  
}

