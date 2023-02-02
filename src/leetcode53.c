#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #动态规划 #分治 #数组 #子数组
/*  53. 最大子数组和

给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个有序部分。 
*/
// 最朴素的就是暴力搜
#define IMAX(a,b) ((a)<(b)?(b):(a))
// 遍历实现 O(n^2) //子数组
int maxSubArray0(int* nums, int numsSize){
	int s=nums[0],sj=0;
	for (size_t i = 0; i < numsSize; i++)
	{
		for (size_t j = i; j < numsSize; j++)
		{
			sj+=nums[j];
			s=IMAX(s,sj);
		}
		sj=0;
	}
	return s;	
}


/* 动态规划实现

首先这是一个优化问题, 需要维护1个变量: 最大子数组和, 数组的每一个位置都存在这个状态变量.

那就可以考虑使用动态规划求解

状态变量 s[i]:以i结尾的最大数组和

状态转移方程
s[i]=max[s[i-1]+nums[i],nums[i]]

max_i s[i]
 */
int maxSubArray2(int* nums,int numsSize){
	int s=nums[0],pre=0;
	for (size_t i = 0; i < numsSize; i++)
	{

		pre=IMAX(pre+nums[i],nums[i]);//维护i处最大数组和
		s=IMAX(s,pre);//最大数组和
	}
	return s;
}
/* ---------分治--------- */
// #分治
/* 本质上是对区间的二分拆分，
对于拆分的区间需要维护以下4个量
 */
struct Status
{
	int lsum,rsum,isum,msum;
	// 左端点子区间[l-m]最大子段和，右端点[m-r]最大子段和, l-r 区间和, l-r 区间内最大子段和
	// m=(l+r)/2
};

struct Status pushUp(struct Status l,struct Status r)
{
	int isum=l.isum+r.isum;//最方便维护
	int lsum=IMAX(l.lsum,l.isum+r.lsum);//要么就是左区间，左子段和， 要么就是左区间子段和+右区间的左子段和
	int rsum=IMAX(r.rsum,r.isum+l.rsum);//同理
	int msum=IMAX(IMAX(l.msum,r.msum),l.rsum+r.lsum);//区间内子段和要考虑子段是否跨越区间中点m
	return (struct Status){lsum,rsum,isum,msum};
}

/**
 * @brief get 就是基本的状态设置即可
 * 
 * @param a 数组
 * @param l 左端点
 * @param r 右端点
 * @return struct Status 
*/
struct Status get(int*a,int l,int r){
	if (l==r)
	{
		return (struct Status){a[l],a[l],a[l],a[l]};
	}
	//递归的拆分左右区间
	int m=(l+r)>>1;
	struct Status Lsub=get(a,l,m);
	struct Status Rsub=get(a,m+1,r);
	return pushUp(Lsub,Rsub);
}

/**
 * @brief 分治实现
 * 
 */
int maxSubArray(int* nums,int numsSize)
{
	return get(nums,0,numsSize-1).msum;
}

int main(){
	int n[9]={-2,1,-3,4,-1,2,1,-5,4},ans;
	ans=maxSubArray(n,9);
	printf("%d\n",ans);
	return 0;
}