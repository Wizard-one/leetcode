#include <test.h>
/* 34. 在排序数组中查找元素的第一个和最后一个位置

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。 */

// #二分法 #排序 #搜索 

typedef struct range
{
	int l,r;
}range;

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

/* 先通过二分法确定位置,后向左右延拓

官方解答是通过两次二分法来实现,先找到第一个大于等于target left 然后再从left开始找第一个小于等于target 的 right

 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	*returnSize=2;
	int *ans;
	ans=malloc(sizeof(int)*2);
	// 排序数组为空,target超出数组范围的情况
	if (numsSize==0 || nums[0]> target || nums[numsSize-1]<target)
	{
		ans[0]=-1;
		ans[1]=-1;
		return ans;
	}
	// 二分查找找到位置
	int loc=get(nums,target,0,numsSize-1).l;
	// 排除没有找到的情况
	if (nums[loc]!=target)
	{
		ans[0]=-1;
		ans[1]=-1;
		return ans;
	}
	// 左右延拓
	int i=loc+1;
	while (i<numsSize && nums[i]==target)
		i++;
	ans[1]=i-1;

	i=loc-1;
	while (i>=0 && nums[i]==target)
		i--;
	ans[0]=i+1;
	return ans;
}

int main(){
	int l[]={5,7,7,8,8,10},relen,*ans;
	ans=searchRange(l,6,8,&relen);
	printf("%d,%d",ans[0],ans[1]);
}