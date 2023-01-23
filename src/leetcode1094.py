from lib.test import *
"""
1094. 拼车

 车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）

给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有 numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。

当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。

 """
#  #差分数组 #子数组
class Solution:

	""" 记录一个数组每一个车站人数是否超载即可，注意to 是代表乘客下车，所以使用差分数组时是在 to处进行-- """
	def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
		diff=[0]*1000
		for trip in trips:
			val=trip[0]
			st=trip[1]
			ed=trip[2]
			# 当上车人数已经超出限定，不管咋地都false
			if val>capacity: return False
			diff[st]+=val
			# ed 出下车 -- 而不是ed+1
			if(ed<len(diff)):
				diff[ed]-=val
		# 恢复差分数组
		nums=[0]*len(diff)
		nums[0]=diff[0]
		for i in range(1,len(diff)):
			nums[i]=nums[i-1]+diff[i]
			if nums[i]>capacity:  return False
		return True
		
if __name__ == "__main__":
	s=Solution().carPooling
	print(s([[2,1,5],[3,5,7]],3))


