// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
//13 14 15 16
#include<stdio.h> 
int main(){ 
    int n; 
    scanf("%d",&n); 
    int num=1; 
    if(n==1){ 
        printf("  1\n"); 
    } 
    else{ 
        for(int i=0;i<n;i++){ 
            if(num<=9){ 
                printf("  %d",num); 
            } 
            else{ 
                printf(" %d",num); 
            } 
            num++; 
            for(int j=1;j<n;j++){ 
                if(num<10){ 
                    printf("  %d",num); 
                } 
                else{ 
                    printf(" %d",num); 
                } 
   
                num++; 
                if(j==n-1){ 
                    printf("\n"); 
                } 
            } 
        }  
    } 
    return 0; 
}  