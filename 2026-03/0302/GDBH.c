#include<stdio.h>
#include<math.h>
int isPrime(int num);
int main(){
    int x;
    scanf_s("%d",&x);
    if(x<6||x%2==1){
        printf("Error!\n");
    }
    
    for(int y=3;y<=x/2;y++){
        for(int z=x-3;z>=x/2;z--){
            if(isPrime(y)){
                break;
            }

            if(isPrime(y)==0&&isPrime(z)==0&&y+z==x){
                printf("%d=%d+%d\n",x,y,z);
            }
        }
    }
    return 0;
}

int isPrime(int num){
    if(num<=1||num%2==0) return 1;
    if(num==2) return 0;
    for(int i=3;i<=sqrt(num);i+=2){
        if(num%i==0) return 1;
    }
    return 0;
}