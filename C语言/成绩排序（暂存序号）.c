//题目内容：从键盘输入3个同学4门课的成绩，将其按平均分从高到低排序输出。
//输入样例：
//89 78 80 76 88 78 75 90 99 92 100 89[回车]
//输出样例：
//99,92,100,89[回车]
//88,78,75,90[回车]
//89,78,80,76[回车]

#include<stdio.h>
int main(){
	int score[3][4];
	float aver[3];
	int arr[3]={0,1,2};

	for(int i=0;i<3;i++){
		int sum=0;
		for(int j=0;j<4;j++){
			scanf("%d",&score[i][j]);
			sum+=score[i][j];
		}
		aver[i]=sum/4.0;
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2-i;j++){
			if(aver[arr[j]]<aver[arr[j+1]]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(int j=0;j<3;j++){
		int index=arr[j];
		for(int k=0;k<4;k++){
			printf("%d",score[index][k]);
			if(k<3)printf(",");
			else printf("\n");
		}
	}

	return 0;
}