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