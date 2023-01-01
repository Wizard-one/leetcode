from lib.test import *

"""
986. 区间列表的交集

 给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。每个区间列表都是成对 不相交 的，并且 已经排序 。

返回这 两个区间列表的交集 。

形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。

两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。
 """

# #区间 [[56]] [[435]] #数学 #双指针

""" 
关注给定区间为每个区间列表都是成对 不相交 的，并且 已经排序 

同时经过分析发现，要发生交集，是A/B的起始点出现在另一个区间内，

而停止交集的条件是终止点用过

例如
A:[1,3], [4,7]

B:[2,4]

B的区间[2,4] 的起始点 2 在 A的区间[1,3]当中说明发生交集, 而3<4 说明该区间已经用过或者例如 [1,3] [4,7] 不会发生交集

由于每个区间列表都不会相交, 并不会出现 3 这个终点出现2次的情况,所以当3被用过之后就代表[1,3]这个区间被用过了
"""
class Solution:
	def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
		n1=len(firstList)
		n2=len(secondList)
		i,j=(0,0)
		ans=[]
		while(i<n1 and j<n2):
			# 起始点一定是两个区间中起始点大的那一个
			st=max(firstList[i][0],secondList[j][0])
			# 终点一定是两个区间中终止点小的那一个
			ed=min(firstList[i][1],secondList[j][1])
			if st<=ed:
				# 起始点小于终点说明是合法区间
				ans.append([st,ed])
			# 终点小的区间已经用过了所有需要跳过
			if firstList[i][1]>secondList[j][1]:
				j+=1
			else:
				i+=1
	
		return ans