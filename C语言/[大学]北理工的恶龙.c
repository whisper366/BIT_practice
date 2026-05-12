#include<stdio.h>
#include<stdlib.h>
int increase(const void *a,const void *b){
	int ia=*(int*)a;
	int ib=*(int*)b;
	return ia-ib;
}
int main(){
	int n,m,i,j,sum=0;
	scanf("%d %d",&n,&m);
	int *drag=(int *)malloc(n*sizeof(int));
	int *man=(int*)malloc(m*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&drag[i]);
	}
	for(j=0;j<m;j++){
		scanf("%d",&man[j]);
	}
	if(n>m){
		printf("bit is doomed!\n");
		return 0;
	}
	else{
		qsort(drag,n,sizeof(int),increase);
		qsort(man,m,sizeof(int),increase);
		for(i=0,j=0;i<m;i++){
			if(j==n) break;
			if(drag[j]<=man[i]){
				sum+=man[i];
				j++;
			}
		}
		if(j!=n){
			printf("bit is doomed!\n");
		}
		else printf("%d\n",sum);
	}
	return 0;
}