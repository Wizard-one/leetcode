// Boyer-Moore 投票算法
#include <stdio.h>
#include <stdlib.h>

// #数组 #其他方法 
int majorityElement(int* nums, int numsSize){
	int count=1,ans=nums[0];
	for (size_t i = 1; i < numsSize; i++)
	{
		// 如果相同，就计数++
		if (nums[i]==ans)
		{
			count++;
		}
		// 如果不同，计数--
		else
		{
			count--;
		}
		// 计数清空了，说明这不是majority，切换此时majority，重新开始计数
		if (count==-1)
		{
			ans=nums[i];
			count=1;
		}
	}
	return ans;
}

int main()
{
	int l[]={6,6,6,7,7},ans;
	ans=majorityElement(l,5);
	printf("%d",ans);
}