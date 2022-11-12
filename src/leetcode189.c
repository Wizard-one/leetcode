#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// 轮转数组 #mid
// 数组翻转很好用
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