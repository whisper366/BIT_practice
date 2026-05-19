#include<stdio.h>
int main(){
    int n,m;
    int count=0;
    while(1){
        scanf("%d %d",&n,&m);
        if(m==0&&n==0) break;
		if(count!=0)printf("\n");
        char map[105][105]={0};
        int ans[105][105]={0};          // 改为 int，避免溢出（虽然 char 也够）
        for(int i=0;i<n;i++){
            scanf("%s",map[i]);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]=='*'){
                    // 8 个方向分别判断
                    // 左上
                    if(i-1>=0 && j-1>=0) ans[i-1][j-1]++;
                    // 上
                    if(i-1>=0) ans[i-1][j]++;
                    // 右上
                    if(i-1>=0 && j+1<m) ans[i-1][j+1]++;
                    // 左
                    if(j-1>=0) ans[i][j-1]++;
                    // 右
                    if(j+1<m) ans[i][j+1]++;
                    // 左下
                    if(i+1<n && j-1>=0) ans[i+1][j-1]++;
                    // 下
                    if(i+1<n) ans[i+1][j]++;
                    // 右下
                    if(i+1<n && j+1<m) ans[i+1][j+1]++;
                }
            }
        }

        printf("Field #%d:\n",++count);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]=='*') printf("*");
                else printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}