//本题关键在于：结果为整数就输出整数，小数就保留两位
#include<stdio.h>
#include<math.h>
int main(){
	char name[4][20]={"wanglei","lihong","zhangli","liuming"};
	int score[4][4]={78,90,87,92,88,91,89,78,84,76,83,75,88,90,71,83};
	float avg_stu[4],avg_cla[4];
	int sum_stu[4]={0},sum_cla[4]={0};
	int index=0;
	while(index<4){
		for(int i=0;i<4;i++){
			sum_stu[index]+=score[index][i];
			avg_stu[index]=sum_stu[index]/4.0;
		}
		 // 判断是否为整数（误差 < 1e-6）
        if (fabs(avg_stu[index] - (int)avg_stu[index]) < 1e-6)
            printf("%s,%d\n", name[index], (int)avg_stu[index]);
        else
            printf("%s,%.2f\n", name[index], avg_stu[index]);
		index++;
	}
	printf("AVERAGE:");
	int temp=0;
	while(temp<4){
		for(int i=0;i<4;i++){
			sum_cla[temp]+=score[i][temp];
			avg_cla[temp]=sum_cla[temp]/4.0;
		}
		if (fabs(avg_cla[temp] - (int)avg_cla[temp]) < 1e-6)
            printf("%d", (int)avg_cla[temp]);
        else
            printf("%.2f", avg_cla[temp]);
		if(temp!=3)printf(",");
		else printf("\n");
		temp++;
	}
	return 0;
}