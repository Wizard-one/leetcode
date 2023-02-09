from lib.test import *
""" 2517. 礼盒的最大甜蜜度

给你一个正整数数组 price ，其中 price[i] 表示第 i 类糖果的价格，另给你一个正整数 k 。

商店组合 k 类 不同 糖果打包成礼盒出售。礼盒的 甜蜜度 是礼盒中任意两种糖果 价格 绝对差的最小值。

返回礼盒的 最大 甜蜜度。
"""
# #最大最小 #二分法
class Solution:
	""" 先对数组排序，最大甜蜜度mx, mx越大说明可以选择的糖果越少，说明问题有单调性
	使用 cnt>=k 作为二分法的筛选条件，搜索单调性的右边界
	 """
	def maximumTastiness(self, price: List[int], k: int) -> int:

		price.sort()
		def check(d:int):
			x0=price[0]
			cnt=1
			for x in price:
				# 从前向后遍历数组，满足当前最小甜蜜度 cnt++
				if x>=x0+d:
					cnt+=1
					x0=x
			return cnt
		right=price[-1]-price[0]
		left=0
		while(left<right):
			mid=left+(right-left)//2
			cnt=check(mid)
			if cnt>=k:
				left=mid+1
			else:
				right=mid
		# 搜索右边界，要处理遇到数组右边界的情况
		if left==price[-1]-price[0]:
			return left
		return left-1

if __name__ == "__main__":
	s=Solution().maximumTastiness
	print(s([1,3,1],2))
