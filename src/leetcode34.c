#include <test.h>
/* 34. 在排序数组中查找元素的第一个和最后一个位置

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。 */

// #二分法 #排序 #搜索 


/* 先通过二分法确定位置,后向左右延拓, 但是延拓相对来说还可以使用二分法加速

所以官方解答是通过两次二分法来实现,先找到第一个大于等于target left 然后再从left开始找第一个小于等于target 的 right

 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	*(returnSize)=2;
	int *ans;
	ans=malloc(sizeof(int)*2);
	int l=0,r=numsSize,m;
	// 先搜索左边界
	while (l<r)
	{
		m=l+(r-l)/2;
		if (nums[m]==target)
			r=m;
		else if (nums[m]>target)
			r=m;
		else
			l=m+1;
	}
	if (l==numsSize || nums[l]!=target)
	{
		ans[0]=-1;
		ans[1]=-1;
		return ans;
	}
		
	ans[0]=l;
	// 然后搜索右边界
	r=numsSize;
	while (l<r)
	{
		m=l+(r-l)/2;
		if (nums[m]==target)
			l=m+1;
		else if (nums[m]>target)
			r=m;
		else
			l=m+1;
	}
	ans[1]=l-1;
	return ans;
	
}

int main(){
	int l[]={5,7,7,8,8,10},relen,*ans;
	ans=searchRange(l,6,8,&relen);
	printf("%d,%d",ans[0],ans[1]);
}