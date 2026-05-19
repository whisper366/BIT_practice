#include<stdio.h>
#include<stdlib.h>

int counter(int x, int y)
{
	int* number = (int*)malloc(x * sizeof(int));	
	for (int i = 0; i < x; i++)
	{
		number[i] = i + 1;
		
	}

	int count = 0;	//被淘汰人数
	int step = 0;	//移动步数
	int index = 0;		//位置

	while (count < x - 1)
	{
		if (number[index] != 0)	//先检查是否被淘汰
		{
			step++;
			if (step == y)	//进一步检查是否需要被淘汰
			{
				count++;
				number[index] = 0;
				step = 0;
			}
		}
		index = (index + 1) % x;
	}
	int winner = 0;
	for (int i = 0; i < x; i++)
	{
		if (number[i] != 0)		
		{
			winner = number[i];
		}
	}
	free(number);
	return winner;
}

int main()
{
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	int winner = counter(m, n);
	printf("The left child is NO %d.\n", winner);
	return 0;
}