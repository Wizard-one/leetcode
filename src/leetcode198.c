#include <stdlib.h>
#include <stdio.h>

#define IMAX(a,b) ((a)>(b)?(a):(b))

/* 198. 打家劫舍

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 */


// #动态规划 [[70]] [[53]] [[121]] #谜语 #数组 
/* f(x): x处最大累积和 */
int rob(int* nums, int numsSize){
	// 边界条件:
	if (numsSize==1)
	{
		return nums[0];
	}
	else if (numsSize==2)
	{
		return IMAX(nums[0],nums[1]);
	}
	int sum=0,sprev1=IMAX(nums[0],nums[1]),sprev2=nums[0];
	// 递推关系: $f(x)=\max[f(x-1),f(x-2)+n(x)]$
	
	for (size_t i = 2; i < numsSize; i++)
	{
		sum=IMAX(sprev1,sprev2+nums[i]);
		sprev2=sprev1;
		sprev1=sum;
	}
	return sum;
}