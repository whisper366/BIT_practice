/*(1) 自2012年4月9日至2012年7月7日：3和8、4和9、5和0、1和6、2和7(含临时号牌，机动车车牌尾号为英文字母的按0号管理，下同)；
　　(2) 自2012年7月8日至2012年10月6日：2和7、3和8、4和9、5和0、1和6；
　　(3) 自2012年10月7日至2013年1月5日：1和6、2和7、3和8、4和9、5和0；
　　(4) 自2013年1月6日至2013年4月10日：5和0、1和6、2和7、3和8、4和9。*/
#include<stdio.h>
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int delta_days(int y,int m,int d){
    int baseY=2012,baseM=4,baseD=9;
    int month_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int days=0;
    for(int i=baseY;i<y;i++){
        days+=(isLeapYear(i)?366:365);
    }
    for(int j=0;j<m-1;j++){
        days+=month_days[j];
        if(j==1&&isLeapYear(y)) days++;
    }
    days+=d;
    int delt=0;
    for(int k=0;k<baseM-1;k++){
        delt+=month_days[k];
        if(k==1&&isLeapYear(baseY)) delt++;
    }
    delt+=baseD;
    days-=delt;
    return days;
}
int main( ){
    int y,m,d;
    scanf("%d %d %d",&y,&m,&d);
    int num[5][2]={{3,8},{4,9},{5,0},{1,6},{2,7}};
    //计算输入日期与基准日期的天数差
    int days=delta_days(y,m,d);
    int weekday=(days+1)%7;
    if(weekday==6||weekday==0){
        printf("Free.\n");
        return 0;
    }
    //13*7=91 index用于确定在周一到周五的哪一天
    int cycle=days/91;
    int index=cycle%5;
    int row=(weekday-1-index+5)%5;
    printf("%d and %d.\n",num[row][0],num[row][1]);
    return 0;
}