#include<stdio.h>
#include<stdlib.h>
int main(){
    int num[4];
    for(int i=0;i<4;i++){
        scanf("%d",&num[i]);
    }
    int max=num[0];
    for(int i=0;i<4;i++){
        if(num[i]>max)max=num[i];
    }
    int max_sum=5*max;
    
    //reachable[x]==1表示能够达到邮资x
    int *reachable=(int*)calloc(max_sum+1,sizeof(int));
    reachable[0]=1;
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5-i;j++){
            for(int k=0;k<=5-i-j;k++){
                for(int p=0;p<=5-i-j-k;p++){
                    int sum=i*num[0]+j*num[1]+k*num[2]+p*num[3];
                    if(sum<=max_sum) reachable[sum]=1;
                }
            }
        }
    }
    int m=0;
    while(m<=max_sum&&reachable[m]){
        m++;
    }
    printf("The max is %d.\n",m-1);
    return 0;
}