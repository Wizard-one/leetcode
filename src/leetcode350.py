from typing import List
import collections
""" 
350. 两个数组的交集 II

给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
 """
class Solution:
	""" 用hash表统计 """
	def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
		# 始终让 nums2 是长的
		if len(nums1) > len(nums2):
			return self.intersect(nums2, nums1)
		# 做hash表
		m = collections.Counter()
		for num in nums1:
			m[num] += 1
		# 然后对nums2 循环，只添加在num1 中有的元素
		intersection = list()
		for num in nums2:
			if (count := m.get(num, 0)) > 0:
				intersection.append(num)
				m[num] -= 1
				if m[num] == 0:
					m.pop(num)
		
		return intersection

if __name__=="__main__":
	s=Solution()
	s.intersect([1,2,2,1],[2,2])