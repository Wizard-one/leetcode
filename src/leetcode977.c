#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
sortedSquares (int *nums, int numsSize, int *returnSize)
{
	int m=numsSize;
	int *ans;
	*returnSize=numsSize;
	ans=calloc(numsSize,sizeof(int));
	for (size_t i = 0; i < numsSize; i++)
	{
		/* code */
		if(nums[i]>=0)
		{
			m=i;
			break;
		}
	}
	int q=m-1,p=m;
	for (size_t i = 0; i < numsSize; i++)
	{
		if (q>-1 && p<numsSize)
		{
			if(-nums[q]>nums[p])
			{
				ans[i]=nums[p]*nums[p];
				p++;
				continue;
			}
			else
			{
				ans[i]=nums[q]*nums[q];
				q--;
				continue;
			}
		}
		if (q==-1)
		{
			ans[i] = nums[p] * nums[p];
			p++;
        }
		else if(p==numsSize)
		{
			ans[i] = nums[q] * nums[q];
			q--;
		}
	}
	return ans;
}

int main()
{
	int a[]={-4,-3,-1,0,2},*ans,resize;
	ans=sortedSquares(a,5,&resize);
	for (size_t i = 0; i < 5; i++)
	{
		/* code */
		printf("%d,",ans[i]);
	}
	
}