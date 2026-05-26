//输入一个数列（长度已知）
//输出最大等值数列段的区间（即下标）
//注意这个等值数列段中的数字必须是一样的（1111，而不是1011）
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	int left=0,right=0;	//最长段的始末位置
	int max_len=0;	//最长段的长度
	int found=0;
	
	for(int i=0;i<n;){	//i指向当前段的起始
		int j=i;
		while(j<n-1&&A[j+1]==A[i]) j++;
		int len=j-i+1;
		if(len>=2&&len>max_len){
			max_len=len;
			left=i;
			right=j;
			found=1;
		}
		i=j+1;	//跳到下一段
	}
	if(found)printf("The longest equal number list is from %d to %d.\n",left,right);
	if(!found) printf("No equal number list.\n");
	return 0;
}