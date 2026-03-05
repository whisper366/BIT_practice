#include<stdio.h>
int main(){
    unsigned long long n;
    scanf_s("%llu",&n);

    if(n==0){
        printf("Yes\n");
        return 0;
    }

    char Bin[65];
    int index=0;

    while(n>0){
        Bin[index++]=(n&1)?'1':'0';
        n>>=1;
    }
    Bin[index]='\0';

    int isPalindrome=1;
    for(int i=0;i<index;i++){
        if(Bin[i]!=Bin[index-1-i]){
            isPalindrome=0;
            break;
        }
    }

    if(isPalindrome){
        printf("Yes\n");
    }
    else printf("No\n");

    return 0;
}