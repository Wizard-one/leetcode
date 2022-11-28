#include <stdlib.h>
// #子数组 [[56]]
// 时间复杂度太高
int subarraySum(int* nums, int numsSize, int k){
	int count=0;
	int sum=0;
	for (size_t i = 0; i < numsSize; i++)
	{
		sum=0;
		for (int j = i; j >= 0; j--)
		{
			sum+=nums[j];
			if (sum==k)
			{
				count++;
			}
		}
		
	}
	return count;
	
}