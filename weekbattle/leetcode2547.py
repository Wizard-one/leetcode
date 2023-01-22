from lib.test import *

"""
2547. 拆分数组的最小代价

 给你一个整数数组 nums 和一个整数 k 。

将数组拆分成一些非空子数组。拆分的 代价 是每个子数组中的 重要性 之和。

令 trimmed(subarray) 作为子数组的一个特征，其中所有仅出现一次的数字将会被移除。

    例如，trimmed([3,1,2,4,3,4]) = [3,4,3,4] 。

子数组的 重要性 定义为 k + trimmed(subarray).length 。

    例如，如果一个子数组是 [1,2,3,3,3,4,4] ，trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4] 。这个子数组的重要性就是 k + 5 。

找出并返回拆分 nums 的所有可行方案中的最小代价。

子数组 是数组的一个连续 非空 元素序列。 """

# #子数组 #动态规划 #hard

class Solution:
	""" 
	难点有2个
	1. 如何维护 cost 函数
	2. 如何进行子数组拆分

	首先子数组+拆分 同时不需要维护路径就是动态规划

	那么定义子数组的方法就是 一个 j-i 的分段，思考一个简单的case
	ind : 0 1 2 3
	nums: 1 1 2 2
	ind=3答案一定是 dp[j]+cost(j,3) j \in [0,3] 组成的
	即前一段的最小cost+后一段的cost，然后对j进行遍历求当前段最小，从而得到状态转移方程为

	f[i]: 以i为结尾的子数组mincost
	f[i]=min(f[j-1]+cost(j,i))+k j \in [0,i] 
	注意到j-1 在 j=0 时 是不可维护的 所以改为
	f[i+1]=min(f[j]+cost(j,i))+k j \in [0,i] 

	那么根据cost 就是i-j+1-unique: 只出现过一次的数字
	"""
	def minCost(self, nums: List[int], k: int) -> int:
		dp=[0]*(len(nums)+1)
		
		for i in range(len(nums)):
			mn=len(nums)*k
			cnt=collections.defaultdict(int)#统计出现次数
			unique=0
			for j in range(i,-1,-1):
				x=nums[j]
				cnt[x]+=1
				# 只出现一次 unique计数
				if cnt[x]==1:
					unique+=1
				# 出现两次 unique-1 
				elif cnt[x]==2:
					unique-=1
				# 动态转移方程
				mn=min(dp[j]+i-j+1-unique,mn)
			dp[i+1]=mn+k
		return dp[-1]

if __name__ == "__main__":
	s=Solution().minCost
	print(s([1,2,1,2,1,3,3],2))