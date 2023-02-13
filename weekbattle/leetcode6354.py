from lib.test import *
""" 给你一个下标从 0 开始的整数数组 nums 。

现定义两个数字的 串联 是由这两个数值串联起来形成的新数字。

    例如，15 和 49 的串联是 1549 。

nums 的 串联值 最初等于 0 。执行下述操作直到 nums 变为空：

    如果 nums 中存在不止一个数字，分别选中 nums 中的第一个元素和最后一个元素，将二者串联得到的值加到 nums 的 串联值 上，然后从 nums 中删除第一个和最后一个元素。
    如果仅存在一个元素，则将该元素的值加到 nums 的串联值上，然后删除这个元素。

返回执行完所有操作后 nums 的串联值。 """

class Solution:
	def findTheArrayConcVal(self, nums: List[int]) -> int:
		n=len(nums)
		su=0
		for i in range(n//2):
			tmp=str(nums[i])+str(nums[-i-1])
			# print(tmp)
			su+=int(tmp)
		if n%2==1:
			su+=nums[n//2]
		return su

if __name__ == "__main__":
	s=Solution().findTheArrayConcVal
	print(s([5,14,13,8,12]))
