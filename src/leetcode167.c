#include <stdio.h>
#include <stdlib.h>
/**167. 两数之和 II - 输入有序数组

给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。
 */

// #双指针 #二分法 #排序

/* 搜索问题就可以考虑二分法
由于已经预先排序，所以可以直接用二分法来搜索目标，
先固定一个值，然后在余下序列中搜索剩下一个值，没有搜索到就继续前进直到用完列表 */
int binary(int l, int r,int* nums, int t)
{
	int m=(l+r)/2;
	while (l<=r)
	{
		if (nums[m]==t)
		{
			return m;
		}
		else if (nums[m]>t)
		{
			r=m-1;
			m=(l+r)/2;
		}
		else
		{
			l=m+1;
			m=(l+r)/2;
		}
	}
	return -1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	*returnSize=2;
	int *ans;
	ans=malloc(sizeof(int)*2);

	for (size_t i = 0; i < numbersSize; i++)
	{
		ans[1]=binary(i+1,numbersSize-1,numbers,target-numbers[i]);
		if(ans[1]!=-1)//搜到了
		{
			ans[0]=i+1;
			ans[1]++;
			break;
		}
	}
	return ans;
}

int main(){
	int a[4]={0,0,2,2},t=2,*ans,re;
	ans=twoSum(a,4,t,&re);
	printf("%d,%d",ans[0],ans[1]);
}