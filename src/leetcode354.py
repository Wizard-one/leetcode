from lib.test import *
""" 俄罗斯套娃信封问题

 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封 """
# #动态规划 [[300]] #耐心排序

# 耐心排序的实现
def poker(nums:List[int]):
	n=len(nums)
	heap=[nums[0]]
	for i in range(1,n):
		cur=nums[i]
		if cur>heap[-1]:
			heap.append(cur)
			continue
		elif cur<heap[0]:
			heap[0]=cur
			continue
		le=0
		ri=len(heap)
		while(le<ri):
			mid=le+(ri-le)//2
			if le<len(heap) and cur>heap[mid]:
				le=mid+1
			elif cur<=heap[mid]:
				ri=mid
		heap[le]=cur
	print(heap)
	return len(heap)


class Solution:
	""" 
	二维的最长递增数组，
	先对w进行升序排序，将问题降维，为了凸显h的差异，就对h进行降序排序
	问题就转化为求h的最长递增数组问题例如
	[[2, 3], [5, 4], [6, 7], [6, 4]]
	对h求最长递增数组 [6,7] 就不能放在 [6,4] 之前

	但是考虑到性能，这边必须采用二分法进行加速，这边使用耐心排序来实现

	使用一个堆，堆内升序排列，将未处理元素始终替换比他大的元素，如果有多个比他大的元素放在最左侧
	当堆内没有比他大的元素时，在堆尾添加该元素。
	堆始终升序的添加过程是在有序列表中搜索位置替换，所以可以用二分法来加速。
	"""
	def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
		envelopes.sort(key=lambda x: (x[0], -x[1]))
		n=len(envelopes)
		heap=[envelopes[0][1]]#建堆，存储一个元素

		for i in range(1,n):
			# 当前处理元素
			cur=envelopes[i][1]
			# 大于队尾，直接添加
			if cur>heap[-1]:
				heap.append(cur)
				continue
			# 小于队首，直接覆盖队首
			elif cur<=heap[0]:
				heap[0]=cur
				continue
			# 二分法，搜索区间[left,right)
			le=0
			ri=len(heap)
			# print(i,":",heap)
			while(le<ri):
				mid=le+(ri-le)//2
				# 需要防止le越界，由于搜索区间[le,ri) 所以le=mid+1
				if le<len(heap) and cur>heap[mid]:
					le=mid+1
				# 如果出现相同数字，放在左侧起始点，即ri是不包含的
				elif cur<=heap[mid]:
					ri=mid
			if le==len(heap):
				heap.append(cur)
			else:
				heap[le]=cur
		# print(heap)
		return len(heap)

if __name__ == "__main__":
	s=Solution().maxEnvelopes
	print(s([[1,15],[7,18],[7,6],[7,100],[2,200],[17,30],[17,45],[3,5],[7,8],[3,6],[3,10],[7,20],[17,3],[17,45]]))
	# poker([6,3,5,10,11,2,9,14,13,7,4,8,12])