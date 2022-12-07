#include <stdlib.h>
#include <stdio.h>
// #数组 #双指针

/* 删除有序数组中的重复项


给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 */

/* 双指针,fidx指向处理过的数据,i指向未处理的数据 */
int removeDuplicates(int* nums, int numsSize){
    int fidx=0;//记录处理过的节点的指针
    for(size_t i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[fidx]){
            // 处理过的最后一个点和未处理的点不同,更新前驱指针
            nums[++fidx]=nums[i];
        }
    }
    return ++fidx;
}

int main(){
	int a[3]={1,1,2},k;
	k=removeDuplicates(a,3);
	for (size_t i = 0; i < k; i++)
	{
		/* code */
		printf("%d,",a[i]);
	}
	printf("\n");
	return 0;
}