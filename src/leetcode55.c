#include <test.h>

/*
55. 跳跃游戏

给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。 */

// #贪心

/* 
先介绍一个不够简洁的方法

出现不可到达的情况是什么? 那就是在数组中出现了一串0，然后之前的步数都无法越过这一串0

例如[3,2,1,0,1,4]

那么问题就转化为从左向右搜索0串的长度，然后回退看是否能到达0串的下一个index
 */
bool canJump(int* nums, int numsSize){

	int countzero=0;
	if(numsSize==1)//数组长度为1 不论什么情况都是可以达到
		return true;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i]==0)
		{
			// 计算0串长度
			countzero=1;
			int j=i+1;
			while (j<numsSize && nums[j]==0)
			{
				countzero++;
				j++;
			}
			//倒退搜索看是否能够越过
			for (j=i-1; j >=0; j--)
			{
				// 检测是否能够越过，或者直接到达终点
				if (nums[j]>countzero || j+nums[j]==numsSize-1)
				{
					// 能越过就到达零串的下一个节点，保证了到达的i是非0
					i=j+countzero;
					break;
				}
				countzero++;
			}
			// 如果不能越过，那么说明无法到达终点，所以false
			if(j==-1)
			{
				return false;
			}
		}
	}
	return true;
}

// time: O(n) #动态规划
/* 介绍一个贪心的方法，只需要维护f(i): i处可以到达最远的位置

f(x)=max[f(x-1),i+nums[i]]
 */

bool canJump(int* nums, int numsSize){
	int maxrange=nums[0];//边界条件 f(0)=nums[0]
	for (size_t i = 0; i < numsSize; i++)
	{
		if (i<=maxrange)
		{
			maxrange=maxrange>(i+nums[i])?(maxrange):(i+nums[i]);
			if (maxrange>=numsSize-1)
			{
				return true;
			}
			
		}
		else
		{
			return false;
		}
		
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int l[]={3,4,0,1,0,0,3,0};
	bool ans=canJump(l,8);
	printf("%d",ans);
	return 0;
}
