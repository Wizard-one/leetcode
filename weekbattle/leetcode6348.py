from lib.test import *
""" 给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：

    选择礼物数量最多的那一堆。
    如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
    选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。

返回在 k 秒后剩下的礼物数量。
 """
#  #模拟 #数学
class Solution:
	# 直接模拟即可
	def pickGifts(self, gifts: List[int], k: int) -> int:
		n=len(gifts)
		for i in range(k):
			ma=max(gifts)
			newma=int(math.sqrt(ma))
			j=gifts.index(ma)
			gifts[j]=newma
		return sum(gifts)

