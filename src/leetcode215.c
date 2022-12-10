#include <stdlib.h>
#include <stdio.h>
#include <test.h>

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
// #排序 #分治 #快速选择 O(n) O(log n) #优先队列

/* 215. 数组中的第K个最大元素

给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。 */

/* 相比排序，不需要让整个序列保证有序，这就使得问题时间复杂度能到达O(n)

而快速选择的实现必然是对O(nlogn)的排序算法的改进,这边直接使用改进后的快排算法 */

//简单的快排分片实现
// 速度不够快可以引入随机化来加速
int Part(int *nums,int low, int high)
{
	int pivotkey;
	pivotkey=nums[low];
	while (low<high)
	{
		while (low<high&&nums[high]>=pivotkey)
		{
			high--;
		}
		swap(&nums[low],&nums[high]);
		while (low<high&&nums[low]<=pivotkey)
		{
			low++;
		}
		swap(&nums[low],&nums[high]);
	}
	return low;
}

/**
 * @brief 升序排列的快速选择
 * 
 * @param nums 
 * @param low 
 * @param high 
 * @param k 
 * @return int 第k大的元素
 */
int quickseclect(int *nums,int low,int high,int k)
{
	int pivot=Part(nums,low,high),res;//快排一次能直接得到元素的正确索引
	if (pivot==k)//索引到达第k个
		return nums[pivot];

	if (pivot>k)
	{
		// 快排的索引大于目标索引,所以目标索引在快排左区间
		res=quickseclect(nums,low,pivot-1,k);
	}
	else
	{
		// 快排的索引小于目标索引,所以目标索引在快排右区间
		res=quickseclect(nums,pivot+1,high,k);
	}
	return res;
}


int findKthLargest(int* nums, int numsSize, int k){
	/* 升序排列，所以第k个最大元素应该是numsSize-k */
	return quickseclect(nums,0,numsSize-1,numsSize-k);
}

int main(){
	int nums[]={3,2,1,5,6,4},numsSize=6,ans,k=2;
	ans=findKthLargest(nums,numsSize,k);
	printf("%d",ans);
}