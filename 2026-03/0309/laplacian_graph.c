//E19943图的拉普拉斯矩阵

#include<stdio.h>
#include<stdlib.h>
void printMatrix(int**matrix,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",matrix[i][j]);
            if(j<n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int **D=(int**)calloc(n,sizeof(int*));
    int **A=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        D[i]=(int*)calloc(n,sizeof(int));
        A[i]=(int*)calloc(n,sizeof(int));
    }
    
    //构建D A
    int num1,num2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&num1,&num2);
        A[num1][num2]=1;
        A[num2][num1]=1;
        D[num1][num1]++;
        D[num2][num2]++;
    }
    //打印矩阵
    int **L=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        L[i]=(int*)calloc(n,sizeof(int));
        for(int k=0;k<n;k++){
            L[i][k]=D[i][k]-A[i][k];
        }
    }
    printMatrix(L,n);

     for (int i = 0; i < n; i++) {
        free(D[i]);
        free(A[i]);
        free(L[i]);
    }
    free(D);
    free(A);
    free(L);
    return 0;
}