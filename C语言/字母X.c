//输入：4 A
//输出：
//D　　　　 D
// C　　  C
//  B　 B
// 　 A
//  Z　 Z
// Y　　　Y
//X　　　　 X
#include <stdio.h>

int main() {
    int n;
    char start;
    scanf("%d %c", &n, &start);
    char temp=start;

    if (start < 'A' || start > 'Z') {
        printf("input error.\n");
        return 0;
    }

    int base=start-'A';
    for(int i=1;i<=2*n-1;i++){
        int offset=n-i;
        int pos=(base+offset)%26;
        if(pos<0) pos+=26;
        char ch='A'+pos;
        //上三角
        if(i<=n){
            for(int j=1;j<=2*n-i;j++){
                if(j==i||j==2*n-i) printf("%c",ch);
                else{
                    printf(" ");
                }
            }
        }
        //下三角
        else{
            for(int k=1;k<=i;k++){
                if(k==i||k==2*n-i) printf("%c",ch);
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}