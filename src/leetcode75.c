#include <stdio.h>
#include <stdlib.h>
/*
75. 颜色分类

 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库内置的 sort 函数的情况下解决这个问题。 
*/
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

// #双指针 #排序 #数组
/* 这里实现方式就是分别标记012开始段，然后遇到什么就放到哪一段
难点是如何维护p0,p1,p2 
实际上用2个指针更加方便，维护压力更小
 */
void sortColors(int* nums, int numsSize){
	int p0=0,p1=0,p2=numsSize-1;//这边分别用3个指针标记012开始段，但实际上用两个指针就可以了，一个标记0结束段 一个标记1结束段
	// 2 一定是放到结尾的 所以p2直接指向结尾
	for (size_t i = 0; i <= p2; i++)
	{
		if (nums[i]==0)
		{
			swap(&nums[p0],&nums[i]);
			p0++;
			p1++;//p1
		}
		else if (nums[i]==1)
		{
			swap(&nums[p1],&nums[i]);
			p1++;
		}
		else if (nums[i]==2)
		{
			swap(&nums[p2],&nums[i]);
			if (p2>0 && i>=0)
			{
				p2--;
				i--;
			}
			else
			{
				break;
			}
		}
		for (size_t j = 0; j < numsSize; j++)
		{
			printf("%d,",nums[j]);
		}
		printf("\n");
		
	}
}


int main(){
	int nums[]={2,0,1},l=3;
	sortColors(nums,l);
	for (size_t i = 0; i < l; i++)
	{
		printf("%d,",nums[i]);
	}
	
}