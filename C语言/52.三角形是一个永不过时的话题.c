//对已知的几个点坐标可能形成的三角形，输出最大面积
//利用海伦公式解决

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		double ans=0;
		int *X=(int*)malloc(N*sizeof(int));
		int *Y=(int*)malloc(N*sizeof(int));
		for(int i=0;i<N;i++){
			scanf("%d %d",&X[i],&Y[i]);
		}

		for(int i=0;i+2<N;i++){
			for(int j=i+1;j<N;j++){
				for(int k=i+2;k<N;k++){
					double a=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
					double b=sqrt((X[i]-X[k])*(X[i]-X[k])+(Y[i]-Y[k])*(Y[i]-Y[k]));
					double c=sqrt((X[k]-X[j])*(X[k]-X[j])+(Y[k]-Y[j])*(Y[k]-Y[j]));
					double s=(a+b+c)/2.0;
					double t=sqrt(s*(s-a)*(s-b)*(s-c));
					if(t>ans) ans=t;
				}
			}
		}
		printf("%.1f\n",ans);
	}
	return 0;
}