#include <stdlib.h>
#include <stdio.h>
int search(int* nums, int numsSize, int target){
	int m;
	int l=0,r=numsSize-1;
	m=(l+r)/2;
	while (l<=r)
	{
		if(target==nums[m])
		{
			return m;
		}
		else if (target>nums[m])
		{
			l=m+1;
		}
		else
		{
			r=m-1;
		}
		m=(l+r)/2;
	}
	return -1;
}

int main()
{
	int a[6]={1,2,3,4,5,6},ans;
	ans=search(a,6,6);
	printf("%d",ans);
}