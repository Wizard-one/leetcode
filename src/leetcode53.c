#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define IMAX(a,b) ((a)<(b)?(b):(a))
// 遍历实现 O(n^2)
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

// 树实现 虽然时间复杂度有所改进，但还是O(n^2)
int maxSubArray1(int* nums, int numsSize){
	int s=nums[0],prev2tree[numsSize];
	for (size_t i = 1; i < numsSize; i++)
	{	
		s=IMAX(s,nums[i]);
		prev2tree[i]=nums[i];
		nums[i-1]=nums[i-1]+nums[i];
	}
	for (size_t i = 1; i < numsSize; i++)
	{
		/* 层遍历 */
		s=IMAX(s,nums[0]);
		for (size_t j = 1; j < numsSize-i; j++) {
			s=IMAX(s,nums[j]);
			nums[j-1]=nums[j-1]+nums[j]-prev2tree[j];
			prev2tree[j]=nums[j];
		}
		
	}
	return s;
}

/* 动态规划实现 */
int maxSubArray2(int* nums,int numsSize){
	int s=nums[0],pre=0;
	for (size_t i = 0; i < numsSize; i++)
	{

		pre=IMAX(pre+nums[i],nums[i]);
		s=IMAX(s,pre);
	}
	return s;
}
/* ---------分治--------- */
struct Status
{
	int lsum,rsum,isum,msum;
};

struct Status pushUp(struct Status l,struct Status r)
{
	int isum=l.isum+r.isum;
	int lsum=IMAX(l.lsum,l.isum+r.lsum);
	int rsum=IMAX(r.rsum,r.isum+l.rsum);
	int msum=IMAX(IMAX(l.msum,r.msum),l.rsum+r.lsum);
	return (struct Status){lsum,rsum,isum,msum};
}

/**
 * @brief 
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