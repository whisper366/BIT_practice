#include<stdio.h>
int main(){
    int score[10];
    for(int i=0;i<10;i++){
        scanf("%d",&score[i]);
    }
    int max_value=-1;
    for(int i=0;i<10;i++){
        if(score[i]>max_value){
            max_value=score[i];
        }
    }
    for(int k=0;k<10;k++){
        if(score[k]==max_value){
            printf("%d\n",k+1);
        }
    }
    return 0;
}