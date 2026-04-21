//它每一位上的数字都两两不相同。我们现在需要找出四位数中某一区间内的这类偶数。
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a,b,i,counter1,c,d,e,f,n;
	a=1,b=1;
	for(n=0;a!=0&&b!=0;n++)
	{
	scanf("%d %d",&a,&b);
	if(a==0&&b==0)
	{
		return 0;
	}
	if(a<1000||b<1000)
	{
		printf("Error\n");
	}
	else
	{
	for(i=a,counter1=0;i<b;i++)
	{
		c=i/1000;
		d=(i-c*1000)/100;
		e=(i-c*1000-d*100)/10;
		f=i-c*1000-d*100-e*10;
		if(a!=c&&a!=d&&a!=e&&a!=f&&c!=d&&c!=e&&c!=f&&d!=e&&d!=f&&e!=f)
        {
			if(i%2==0)
			{
			printf("%-6d",i);
			counter1++;
			}
		}
	}
	printf("\n");
	printf("counter=%d\n",counter1);
	}
	}
	return 0;
}