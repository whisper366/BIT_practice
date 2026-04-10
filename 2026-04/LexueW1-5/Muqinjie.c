// Week5
#include <stdio.h>

int isRun(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main() {
    int year;
    scanf("%d", &year);

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isRun(year)) {
        days[1] = 29;  
    }

    // 计算从1900年1月1日到year年5月1日的总天数
    int total = 0;
    for (int y = 1900; y < year; y++) {
        total += isRun(y) ? 366 : 365;
    }
    for (int m = 0; m < 4; m++) {   // 加上当年1~4月的天数
        total += days[m];
    }

    // 已知1900年1月1日是星期一
    // 用0代表星期一，1代表星期二，...，6代表星期日
    int week = total % 7;   // 5月1日是星期几

    // 计算第一个星期日的日期
    int first_sunday;
    if (week == 6)          // 5月1日正好是星期日
        first_sunday = 1;
    else
        first_sunday = 1 + (6 - week);   // 几天后是星期日

    int mother_day = first_sunday + 7; 

    printf("%d\n", mother_day);
    return 0;
}