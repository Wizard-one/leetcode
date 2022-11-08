#include <math.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct range
{
	int l,r;
}range;

/**
 * @brief 获取插入搜索范围
 * 
 * @param a 搜索数组
 * @param t 搜索目标
 * @param rb 右侧最大边界
 * @param l 左边界
 * @param r 右边界
 * @return range 
 */
range get(int* a,int t,int l,int r)
{
	int m=(l+r)>>1;
	if (a[m]==t)
	{
		return (range){m,m};
	}
	else if (a[m+1]>t && a[m]<t)
	{
		return (range){m+1,m+1};
	}	
	else if (a[m]>t)
	{
		return get(a,t,l,m);
	}
	else
	{
		return get(a,t,m+1,r);
	}
	 
}

int searchInsert(int* nums, int numsSize, int target){
	if (nums[0]> target)
	{
		return 0;
	}
	if (nums[numsSize-1]<target)
	{
		return numsSize;
	}
	return get(nums,target,0,numsSize-1).l;
}

int main(){
	int a[4]={1,3,5,6},ans;
	ans=searchInsert(a,4,5);
	printf("%d",ans); 
	return 0;
}