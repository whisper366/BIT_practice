/*有n支队伍，要求每两支队都要打一场，但是每天一支队只能打一场比赛。
为了完成比赛，希望知道最少需要打多少天？
    输入的第一行是一个整数T，
表示有T组用例（T <= 110）。每组用例为一个整数n(1 <= n <= 10000)，表示队伍的数量。
    每组用例输出一行，为最少需要比赛的天数。*/
#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    int test[T];
    for(int i=0;i<T;i++){
        scanf("%d",&test[i]);
    }
    for(int i=0;i<T;i++){
        if(test[i]==1){
            printf("0\n");
        }
        else if(test[i]%2==0){
            printf("%d\n",test[i]-1);
        }
        else if(test[i]!=1&&test[i]%2==1){
            printf("%d\n",test[i]);
        }
    }

    return 0;
}