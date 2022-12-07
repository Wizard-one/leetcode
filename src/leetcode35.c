#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* 35. 搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
 */

/* 
标准二分法
 */

typedef struct range
{
	int l,r;
}range;
// #搜索 #二分法 #数组 #递归
/**
 * @brief 获取插入搜索范围
 * 
 * 使用递归的二分搜索来解决问题
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
	// 两个终止条件
	if (a[m]==t)
	{
		// 目标值找到返回
		return (range){m,m};
	}
	else if (a[m+1]>t && a[m]<t)
	{
		// 目标值不在列表中返回插入位置
		return (range){m+1,m+1};
	}	
	else if (a[m]>t)
	{
		// 向左递归二分查找
		return get(a,t,l,m);
	}
	else
	{
		// 向右递归二分查找
		return get(a,t,m+1,r);
	}
	 
}
/* 搜索插入位置 */
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