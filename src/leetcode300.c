#include <test.h>

/* 300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 */

// #子序列 #数组 #动态规划

/* 可以使用以nums[i]为结尾的子序列来对子序列进行变量标记与维护

观察给定的数据范围nums.length<=2500 所以可知这是一个O(n^2)可以的题目

进一步思考，子序列需要维护一个递增序列，O(1)扫掠是无法满足搜索到子序列为最长子序列的

使用动态规划求解的话，就需要在每一个位置维护一个 len[i]: 以 i 结尾的最长子序列长度

如果要以i为结尾 len的更新必然满足: 
 
nums[i]> nums[j] j  in [0,i)

而最长的维护就使用 len[i]=max*(len[i],len[j]+1) 即可

最后求 max(len) 即可
 */


#define IMAX(a,b) (a>b)?(a):(b)

int lengthOfLIS(int* nums, int numsSize){
	int last=nums[0],maxlen=1;
	int *len;
	len=malloc(sizeof(int)*numsSize);
	
	for (size_t i = 0; i < numsSize; i++)
	{
		len[i]=1;
		for (size_t j = 0; j < i; j++)
		{
			if (nums[i]>nums[j])
			{
				// 以i 结尾的最长子序列必然是 0-j 最长子序列长度+1 与本身的比较
				len[i]=IMAX(len[i],len[j]+1);
			}
		}
		maxlen=IMAX(len[i],maxlen);//记录最大的 len[i]
	}
	return maxlen;
}

int main(int argc, char const *argv[])
{
	int l[]={0,1,0,2,3};
	int ans=lengthOfLIS(l,5);
	printf("%d",ans);
	return 0;
}
