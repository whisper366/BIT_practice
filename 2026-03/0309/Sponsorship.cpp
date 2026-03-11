//先按总分从高到低排序;如果两个同学总分相同，再按语文成绩从高到低排序;
//如果两个同学总分和语文成绩都相同，那么规定学号小的同学排在前面
//任务：先根据输入的3门课的成绩计算总分，然后按上述规则排序，
//最后按排名顺序输出前五名名学生的学号和总分。

// 输入
// 共 n+1行
// 第 1行为一个正整数 n≤300，表示该校参加评选的学生人数。
// 第 2 到 n+1行，每行有 3 个用空格隔开的数字，每个数字都在 0到 100之间。第 j行的 3个数字依次表示学号为 j−1的学生的语文、数学、英语的成绩。每个学生的学号按照输入顺序编号为 1∼n。

// 输出
// 共 5行，每行是两个用空格隔开的正整数，依次表示前 5名学生的学号和总分。
#include<iostream>
#include<algorithm>
using namespace std;
struct Stu{
    int ch,ma,en;
    int sum;
    int num;
}s[300];

bool cmp(Stu a,Stu b){
    if(a.sum==b.sum){
        if(a.ch==b.ch){
            return a.num<b.num;
        }
        else return a.ch>b.ch;
    }
    else return a.sum>b.sum;
}

int main(){
   int key;
   cin>>key;
   for(int i=1;i<=key;i++){
        cin>>s[i].ch>>s[i].ma>>s[i].en;
        s[i].sum=s[i].ch+s[i].ma+s[i].en;
        s[i].num=i;
    } 
    sort(s+1,s+1+key,cmp);  //注意前两个参数

    for(int j=1;j<=5;j++){
        cout<<s[j].num<<" "<<s[j].sum<<endl;
    }
    return 0;
}