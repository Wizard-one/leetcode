#include <test.h>

/* 283. 移动零

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 */
// #双指针 #数组 [[27]]
/* 相当于在 27 删除元素的基础上 将末尾元素后面的全置0 */
void moveZeroes(int* nums, int numsSize){
	int i,slow=0,t;
	for ( i = 0; i < numsSize; i++)
	{
		// 快慢指针 慢指针维护有序变量,快指针扫掠
		if (nums[i]!=0)
		{
			nums[slow]=nums[i];
			slow++;
		}
	}
	// 随后的变量全置0
	for (; slow < numsSize; slow++)
	{
		nums[slow]=0;
	}
	
}

int main(){
	int a[]={0,1,0,3,5};
	moveZeroes(a,5);
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d,",a[i]);
	}
	
}