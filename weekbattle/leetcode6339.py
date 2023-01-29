from lib.test import *
""" 6339. 将珠子放入背包中

你有 k 个背包。给你一个下标从 0 开始的整数数组 weights ，其中 weights[i] 是第 i 个珠子的重量。同时给你整数 k 。

请你按照如下规则将所有的珠子放进 k 个背包。

    没有背包是空的。
    如果第 i 个珠子和第 j 个珠子在同一个背包里，那么下标在 i 到 j 之间的所有珠子都必须在这同一个背包中。
    如果一个背包有下标从 i 到 j 的所有珠子，那么这个背包的价格是 weights[i] + weights[j] 。

一个珠子分配方案的 分数 是所有 k 个背包的价格之和。

请你返回所有分配方案中，最大分数 与 最小分数 的 差值 为多少。 """
# #子数组 #数学 #贪心
class Solution:
	""" 换一个描述，寻找k-1 个分割点，分割点的价值是分割点两端的值之和，那么k个子区间对应k-1个分割点
	最大值就是前k-1 个最大值之和，最小值同理，两者相减n[0] n[-1] 可忽略不记"""
	def putMarbles(self, weights: List[int], k: int) -> int:
		if k==1:
			return 0
		for i in range(len(weights)-1):
			weights[i]+=weights[i+1]
		weights.pop()
		weights.sort()
		mi=sum(weights[:k-1])
		ma=sum(weights[-(k-1):])
		return ma-mi


if __name__ == "__main__":
	s=Solution().putMarbles
	print(s([1,3,5,1],2))