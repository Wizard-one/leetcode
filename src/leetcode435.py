from typing import List
# [[56]]

# #排序 #贪心 #区间
class Solution:
	def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
		intervals.sort(key=lambda e: e[1])#预先按照区间结束点进行排序
		bcr=intervals[0][1]#区间右侧边界
		ans=1
		print(intervals)
		for i in range(1,len(intervals)):
			# 当前区间点相比上一个加入结果的右端点小
			# e.g [1,3] [2,6] 2<3
			if bcr<=intervals[i][0]:
				#将结果边界更新为大的
				ans+=1
				bcr=intervals[i][1]
		
		return len(intervals)-ans
	
if __name__ == "__main__":
	s=Solution().eraseOverlapIntervals
	res=s([[1,2],[2,3],[3,4],[1,3]])
	print(res)