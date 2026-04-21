#include<stdio.h>
int main(){  
    int h1,m1;  
    scanf("%d %d",&h1,&m1);  
      
    double minute_angle=m1*6.0;  
    double hour_angle;  
    double delt;  
    if(h1==12){  
        hour_angle=m1*0.5;  
        delt=minute_angle-hour_angle;  
        if(delt>180){  
            delt=360-delt;  
        }  
        if(m1<10){  
            printf("At %d:0%d the angle is %.1f degrees.\n",h1,m1,delt);  
        }  
        else{  
            printf("At %d:%d the angle is %.1f degrees.\n",h1,m1,delt);  
        }  
    }  
      
    else{  
        hour_angle=h1*30.0+m1*0.5;  
        delt=hour_angle-minute_angle;  
        if(delt<0) delt=minute_angle-hour_angle;  
        else if(delt>180) delt=360-delt;  
        if(m1<10){  
            printf("At %d:0%d the angle is %.1f degrees.\n",h1,m1,delt);  
        }  
        else{  
            printf("At %d:%d the angle is %.1f degrees.\n",h1,m1,delt);  
        }  
    }  
    return 0;  
}  
