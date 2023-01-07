#include <test.h>

/* 45. 跳跃游戏 II

给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

    0 <= j <= nums[i] 
    i + j < n

返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 */

// #贪心 [[55]]


/* 正向维护最大可到达范围内的最远距离即可。

例如 [2,3,1,1,4]

从0 开始可到达范围为 1,2 其中 nums[1] 可到达距离最远，所以下一步跳转到1 同时step++

 */
int jump(int* nums, int numsSize){
	if (numsSize==1)
	{
		return 0;
	}

	int maxrange=0;//当前范围内到达最远距离
	int count=0;
	int end=0;//当前范围的边界
	
	for (int i = 0; i < numsSize-1; i++)
	{
		maxrange=maxrange>(i+nums[i])?(maxrange):(i+nums[i]);
		// 到达边界，调整边界，同时count++
		if (i==end)
		{
			count++;
			end=maxrange;
		}
		// 边界大于数组范围，退出
		if (end>=numsSize-1)
		{
			return count;
		}
		
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int l[]={7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
	int ans=jump(l,15);
	printf("%d",ans);
	return 0;
}
