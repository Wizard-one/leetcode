#include <test.h>
/* 713. 乘积小于 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。  */


// #连续子数组 #滑动窗 #子数组 #数学 [[6254]]
/* 由于只需要返回子数组的数目，所以问题可以通过滑动窗来进行处理，

滑动窗内需要维护窗内乘积，但是连续子数组如何计数呢?

如果  l-r 乘积> k 那么移动l 同时 l-r 内所有子区间必然都满足 <k 

计数的添加就是 r-l+1

那么这种计数方式是否会发生重复呢?

并不，考虑r移动的情况：

当r移动，cum并没有超过k，那么以r为终点的l-r 区间内所有子区间都需要重新计数的例如
10 5 2 k=101
   count
10   +1
10 5 +2
10 5 2 +3

当l移动，区间起始点重新约定，子区间的重复计数不会发生
 */
int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
	int l=0,r;
	int count=0,cum=1;
	for (r = 0; r < numsSize; r++)
	{
		cum*=nums[r];//区间乘积
		while (l<=r && cum>=k)
		{
			cum/=nums[l];
			l++;
		}
		count+=r-l+1;//每一次区间叠加数目
	}
	return count;
}

int main(){
	int l[]={10,5,2,6};
	int ans=numSubarrayProductLessThanK(l,4,100);
	printf("%d",ans);
}