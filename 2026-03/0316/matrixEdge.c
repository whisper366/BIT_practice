//输入
//第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以一个空格分开。
//接下来输入的m行数据中，每行包含n个整数，整数之间以一个空格分开

//输出
//输出对应矩阵的边缘元素和

#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,n;    
    scanf("%d %d",&m,&n);

    int **matrix=(int**)malloc(m*sizeof(int*));
    if(matrix==NULL){
        return -1;
    }
    for(int i=0;i<m;i++){
        matrix[i]=(int*)malloc(n*sizeof(int));
        if(matrix[i]==NULL){
            for(int j=0;j<i;j++){
                free(matrix[j]);
            }
            free(matrix);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=matrix[0][i];
    }
    //易错：要讨论行与列是否为1，否则会重复计数！！
    if(m>1){
        for(int j=0;j<n;j++){
            sum+=matrix[m-1][j];
        }
    }
    for(int j=1;j<m-1;j++){
        sum+=matrix[j][0];
        if(n>1){
            sum+=matrix[j][n-1];
        }
        
    }
    printf("%d\n",sum);

    for(int i=0;i<m;i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0; 
}