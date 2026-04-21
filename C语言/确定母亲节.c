//母亲节是每年的五月第二个星期天，针对输入的年份，计算该年的哪一天是母亲节。
//输入：年份
//输出：日期（5月的哪一天）
#include<stdio.h>
int isRun(int y){
	if((y%4==0&&y%100!=0)||y%400==0){
		return 1;
	}
	else return 0;
}
int main(){
	int year;
	scanf("%d",&year);
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int total_day=0;
	for(int i=1900;i<year;i++){
		total_day+=isRun(i)?366:365;
	}
	if(isRun(year)){
		days[1]++;
	}
	for(int i=0;i<4;i++){
		total_day+=days[i];
	}
	int week=(total_day)%7;
	if(week==6) week=0;
	else week+=1;
	int first;
	if(week==0){
		first=1;
	}
	else{
		first=1+(7-week);
	}
	int mother_day=first+7;
	printf("%d\n",mother_day);
	return 0;
}