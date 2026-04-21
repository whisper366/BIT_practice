#include<stdio.h>  
int main(){  
    int a,n;  
    scanf("%d %d",&a,&n);  
    if(n<=0) return 0;  

    //修复n==1边界！！
    if (n == 1) {
        printf("%d\n", a % 10);
        return 0;
    }
    
    int total_numbers=3*(n-1);  
    int number[total_numbers];  
    int current=a;  
    for(int i=0;i<total_numbers;i++){  
        if(current>=10){  
            current=current%10;  
        }  
        number[i]=current;  
        current=(current+1)%10;  
    }  
    int index=0;  
    for(int i=0;i<n;i++){  
        if(i==0){  
            for(int j=0;j<n;j++){  
                printf("%d",number[index]);  
                index++;  
            }  
            printf("\n");  
        }   //pass  
        else if(i==n-1){  
            printf("%d\n",number[2*n-2]);  
        }  
        else{  
            printf("%d",number[total_numbers-i]);  
            for(int k=n-3;k>=i;k--){  
                printf(" ");  
            }  
            printf("%d\n",number[index++]);  
        }  
    }  
    return 0;  
}