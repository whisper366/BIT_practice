#include<stdio.h>  
int isRun(int year){  
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))  
        return 1;  
    else  
        return 0;  
}  
int main(){  
    int year,month,date;  
    scanf("%d %d %d",&year,&month,&date);  
      
    int total_day=0;  
    for(int y=1900;y<year;y++){  
        if(isRun(y)){  
            total_day+=366;  
        }  
        else total_day+=365;  
    }  
      
    int month_day[]={31,28,31,30,31,30,31,31,30,31,30,31};  
    if(isRun(year))  month_day[1]=29;  
    for(int i=0;i<month-1;i++){  
        total_day+=month_day[i];  
    }  
      
    total_day+=date-1;  
    int week=(total_day%7)+1;  
    if(week==7) week=0;  
    printf("%d\n",week);  
    return 0;  
}  