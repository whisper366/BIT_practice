//leetcode 53.给你一个整数数组 nums 
//请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
#include<stdio.h>
#include<math.h>

int maxSum(int* nums, int numsSize) {
    int max_sum=nums[0],current_sum=nums[0];
    int n=numsSize;
    for(int i=1;i<n;i++){
        current_sum=((nums[i]>current_sum+nums[i])?nums[i]:current_sum+nums[i]);
        max_sum=((current_sum>max_sum)?current_sum:max_sum);
    }
    return max_sum;
}

int main(){
    int T;  //数组大小
    scanf("%d",&T);
    int *nums;
    for(int i=0;i<T;i++){
        scanf("%d",&nums[i]);
    }
    int max_sum=maxSum(nums,T);
    printf("The max is:%d.\n",max_sum);
    return 0;
}
