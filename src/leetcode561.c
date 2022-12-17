#include <test.h>

#define IMIN(a,b) (a>b)?(b):(a)


/* 
561. 数组拆分
给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。

返回该 最大总和 。
 */


// #数组 #排序

/* 排序取奇数 */
int cmp(const void *a,const void *b)
{
	return *((int *)a)-*((int*) b);
}


int arrayPairSum(int* nums, int numsSize){
	qsort(nums,numsSize,sizeof(int),cmp);
	int i=0,sum=0;
	while (i+1<numsSize)
	{
		sum+=nums[i];
		i+=2;
	}
	return sum;
}