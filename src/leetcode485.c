#include <test.h>
/* 485. 最大连续 1 的个数

给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。 
*/

// #数组 

/* 直接计数不逼逼 */
int findMaxConsecutiveOnes(int* nums, int numsSize){
	int max=0,total=0;
	for (size_t i = 0; i < numsSize; i++)
	{
		if(nums[i]==0)
		{
			total=max>total?(max):(total);
			max=0;
		}
		else
		{
			max++;
		}
	}
	total=max>total?(max):(total);
	return total;
}