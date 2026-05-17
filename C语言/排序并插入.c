#include<stdio.h>
#include<stdlib.h>
int compare_asc(const void *arr,const void *tar){
    return (*(int*)arr-*(int*)tar);
}
int main(){
    int arr[10];
    int num;
    for(int i=0;i<9;i++){
        scanf("%d",&arr[i]);
        if (i < 8) {        
            char comma;
            scanf("%c", &comma);  
        }
    }
    scanf("%d",&num);
    qsort(arr,9,sizeof(int),compare_asc);
    int pos = 0;
    while (pos < 9 && arr[pos] < num) {
        pos++;
    }
    // 后移元素（从后往前移）
    for (int i = 9; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;

    for(int i=0;i<10;i++){
        printf("%d",arr[i]);
        if(i!=9) printf(",");
        else printf("\n");
    }
    return 0;
}