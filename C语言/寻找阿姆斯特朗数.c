//一个 n 位的正整数等于其各位数字的n次方之和。
//所有此n位特殊数。每个数占一行。
//若不存在符合条件的特殊数，则输出提示："No output.”；若存在，则从小到大进行输出。
#include<stdio.h>  
int main(){  
    int n;  
    scanf("%d",&n);  
    int left=1;  
    for(int i=1;i<n;i++){  
        left=left*10;  
    }  
    int right=left*10;  
    int found=0;  
    char str[20];  
    for(int i=left;i<right;i++){  
        int sum=0;  
        snprintf(str,sizeof(str),"%d",i);  
        for(int j=0;j<n;j++){  
            int power=1;  
            int digit=str[j]-'0';  
            for(int k=0;k<n;k++){  
                power*=digit;  
            }  
            sum+=power;  
        }  
        if(sum==i){  
            found=1;;  
            printf("%d\n",i);  
        }  
    }  
    if(!found){  
        printf("No output.\n");  
    }  
    return 0;  
}  