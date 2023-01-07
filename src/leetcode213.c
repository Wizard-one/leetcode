#include <test.h>
/* 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。 */


// #动态规划 [[70]] [[53]] [[198]] [[121]] #谜语 #数组 
/* f(x): x处最大累积和 */

#define IMAX(a,b) ((a)>(b)?(a):(b))

/* 
相比198 首尾相互连通，

当 numsSize<3 这种情况无需考虑

包含首 那考虑的下标范围为[0,numsSize-2]

同理包含尾 那考虑的下标范围为[1,numsSize-1]

那么只需要复用198 使用不同的范围即可
 */

int subrob(int* nums,int st, int ed)
{	
	// 边界条件: 当给定数组长度==1
	if (ed==st)
	{
		return nums[st];
	}
	else if (ed-st==1)
	// 当给定数组长度==2
	{
		return IMAX(nums[st],nums[ed]);
	}
	// sum: f(x) sprev1: f(x-1) sprev2: f(x-2)
	int sum=0,sprev1=IMAX(nums[st],nums[st+1]),sprev2=nums[st];
	// 递推关系: $f(x)=\max[f(x-1),f(x-2)+n(x)]$
	

	for (size_t i = st+2; i <= ed; i++)
	{
		// $f(x)=\max[f(x-1),f(x-2)+n(x)]$
		sum=IMAX(sprev1,sprev2+nums[i]);
		sprev2=sprev1;//f(x-2) 维护
		sprev1=sum;//f(x-1) 维护
	}
	return sum;
}


int rob(int* nums, int numsSize){
	if (numsSize==1)
	{
		return nums[0];
	}
	else if (numsSize==2)
	{
		return IMAX(nums[0],nums[1]);
	}
	int sumst=subrob(nums,0,numsSize-2);
	int sumed=subrob(nums,1,numsSize-1);

	return IMAX(sumst,sumed);
}


int main(int argc, char const *argv[])
{
	int l[]={1,2,3,1};
	int ans=rob(l,4);
	printf("%d",ans);

	return 0;
}
