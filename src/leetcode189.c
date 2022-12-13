#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* 轮转数组
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。 */

//  #mid #数组 time: O(n) space: O(n)
/* 这边直接用额外存储空间，不使用的话就要用数组3次翻转来实现了 */
void rotate(int* nums, int numsSize, int k){
	int mv=k%numsSize;
	int cache[numsSize];
	for (size_t i = 0; i < numsSize; i++)
	{
		cache[(i+k)%numsSize]=nums[i];
	}
	memmove(nums,cache,numsSize*sizeof(int));

}	

int main()
{
	int a[]={1,2,3,4,5};
	rotate(a,5,9);
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d",a[i]);
	}
	
}