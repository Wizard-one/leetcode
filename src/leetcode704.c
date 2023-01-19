#include <stdlib.h>
#include <stdio.h>

/* 704. 二分查找

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */

int search(int* nums, int numsSize, int target){
	int m;
	int l=0,r=numsSize-1;
	while (l<=r)
	{
		m=l+(l-r)/2;//有效的防止数据溢出
		if(target==nums[m])
			return m;
		else if (target>nums[m])
			l=m+1;
		else
			r=m-1;
	}
	return -1;
}

int main()
{
	int a[6]={1,2,3,4,5,6},ans;
	ans=search(a,6,6);
	printf("%d",ans);
}