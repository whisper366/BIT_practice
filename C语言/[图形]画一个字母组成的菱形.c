#include<stdio.h>
int main()
{
	int i,j,n,k;
	char c;
	scanf("%c,%d",&c,&n);
	for(i=0;i<n;i++)				
	{
		for(j=0;j<n+i;j++)
		{
			if(j==n-i-1||j==n+i-1)
			{
				k=c+i;
				A:if((k>=65)&&(k<=90))
					printf("%c",k);		 
				else
				{
					k-=26;
					goto A;
				}
				
			}
			else
			{
				printf(" ");			
			}
		}
		printf("\n");
	}
	for(i=n;i<2*n-1;i++)			
	{
		for(j=0;j<3*n-i-2;j++)
		{
			if(j==3*n-i-3||j==i-n+1)
			{
				k=c+n-1-(i-n+1);
				B:if((k>=65)&&(k<=90))
					printf("%c",k);
				else
				{
					k-=26;
					goto B;
				 } 
			}
			else
				printf(" ");			
		}
		printf("\n");
	}
	return 0;
}
