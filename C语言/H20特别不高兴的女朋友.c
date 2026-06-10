/*输入之和大于等于10就不高兴
如果没有不高兴，输出0
如果有不高兴，输出最不高兴的一天；如果一样，输出时间靠前的一天*/
#include<stdio.h>
int main(){
    int sch[7][2];
    int sum[7]={0};
    for(int i=0;i<7;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&sch[i][j]);
        }
    }
    int date[7];
    int index=0;
    int found=0;
    for(int i=0;i<7;i++){
        sum[i]=sch[i][0]+sch[i][1];
        if(sum[i]>=10){
            date[index++]=i;
            found=1;
        }
    }
    if(found==0) {
        printf("0\n");
        return 0;
    }
    if(index==1) printf("%d\n",date[0]);
    else{
        int ans=1;
        int max=sum[0];
        for(int i=0;i<7;i++){
            if(max<sum[i]){
                max=sum[i];
                ans=i+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}