from typing import List

def takefirst(e):
	return e[0]

# #排序 #数组
""" 
合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
"""
class Solution:
	def merge(self, intervals: List[List[int]]) -> List[List[int]]:
		intervals.sort(key=takefirst)#预先按照区间开始点进行排序
		ans:List[List[int]]=[intervals[0]]
		for i in range(1,len(intervals)):
			# 当前区间点相比上一个加入结果的右端点小
			# e.g [1,3] [2,6] 2<3
			if intervals[i][0]<=ans[-1][1]:
				#将结果边界更新为大的
				ans[-1][1]=max(intervals[i][1],ans[-1][1])
			else:
				# 不然就加入
				# e.g [1,3] [4,5]
				ans.append(intervals[i])
		return ans
	
if __name__ == "__main__":
	s=Solution().merge
	ans=s([[1,3],[2,6],[8,10],[15,18]])
	# ans=s([[1,4],[4,6]])
	print(ans)
			
