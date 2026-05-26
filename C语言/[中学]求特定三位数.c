//将1～ 9 分成 3 个三位数
//要求第2个三位数是第1个的2倍，第3个三位数是第1个的3倍
//输入第一个三位数的数字
//输出满足条件的所有三位数
#include<stdio.h>
int check(int a,int b,int c){
	int num,digit;
	int count[10]={0};
	num=a;
	while(num>0){
		digit=num%10;
		count[digit]++;
		if(digit==0) return 0;
		num/=10;
	}
	
	num=b;
	while(num>0){
		digit=num%10;
		count[digit]++;
		if(digit==0) return 0;
		num/=10;
	}

	num=c;
	while(num>0){
		digit=num%10;
		count[digit]++;
		if(digit==0) return 0;
		num/=10;
	}
	for(int i=1;i<10;i++){
		if(count[i]!=1) return 0;
	}
	return 1;
}
int main(){
	int n,first,second,third;
	scanf("%d",&n);
	int found=0;
	if(n==9){
		printf("0,0,0\n");
		return 0;
	} 
	for(first=123;first<=329;first++){
		second=first*2;
		third=first*3;
		if(second<100||second>999||third<100||third>999){
			continue;
		}
		if(first<n*100||first>(n+1)*100) continue;
		if(check(first,second,third)){
			found=1;
			printf("%d,%d,%d\n",first,second,third);
		}
	}
	if(!found) printf("0,0,0\n");
	return 0;
}