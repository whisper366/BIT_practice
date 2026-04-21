#include<stdio.h>
#include<math.h>
int is_prime(int n) {
    if (n < 2||n%2==0) return 0;
    if (n == 2) return 1;    
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main(){
	int num;
	scanf("%d",&num);
	int prime;
	for(int i=0;i<=num;i++){
		if(is_prime(i)) prime=i;
	}
	printf("The max prime number is %d.\n",prime);
	return 0;
}