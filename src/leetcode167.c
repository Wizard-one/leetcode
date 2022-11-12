#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// #双指针， 二分法
int binary(int l, int r,int* nums, int t)
{
	int m=(l+r)/2;
	while (l<=r)
	{
		if (nums[m]==t)
		{
			return m;
		}
		else if (nums[m]>t)
		{
			r=m-1;
			m=(l+r)/2;
		}
		else
		{
			l=m+1;
			m=(l+r)/2;
		}
	}
	return -1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	*returnSize=2;
	int *ans;
	ans=malloc(sizeof(int)*2);

	for (size_t i = 0; i < numbersSize; i++)
	{
		ans[1]=binary(i+1,numbersSize-1,numbers,target-numbers[i]);
		if(ans[1]!=-1)
		{
			ans[0]=i+1;
			ans[1]++;
			break;
		}
	}
	return ans;
}

int main(){
	int a[4]={0,0,2,2},t=2,*ans,re;
	ans=twoSum(a,4,t,&re);
	printf("%d,%d",ans[0],ans[1]);
}