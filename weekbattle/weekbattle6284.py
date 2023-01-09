from lib.test import *


"""
6284. 使字符串总不同字符的数目相等
 给你两个下标从 0 开始的字符串 word1 和 word2 。

一次 移动 由以下两个步骤组成：

    选中两个下标 i 和 j ，分别满足 0 <= i < word1.length 和 0 <= j < word2.length ，
    交换 word1[i] 和 word2[j] 。

如果可以通过 恰好一次 移动，使 word1 和 word2 中不同字符的数目相等，则返回 true ；否则，返回 false 。 """

# #字符串 #枚举 #hash


""" 
总结：

在实际进行周赛时有一个巨大的误区，那就是对于python底层的忽视， k in keys 这个操作本身对应了什么? 对于list而言就是 O(n) 的全遍历，所以实质上就需要两个for循环一一枚举遍历

题解：
首先使用hash表统计每个字符串的长度，然后遍历两个hash表进行交换的模拟比较

这里面有一个陷阱：恰好一次交换意味着交换必须发生 例如 a,bb 这个不交换能够满足，交换之后反而不能满足

"""
class Solution:
	def isItPossible(self, word1: str, word2: str) -> bool:
		ha1=collections.Counter(word1)
		ha2=collections.Counter(word2)
		# 由于只能交换一次，所以直接模拟交换过程
		for k1,v1 in ha1.items():
			for k2,v2 in ha2.items():
				# 如果两个字符相同，且hash表长度相同就不需要交换
				if k1==k2 and len(ha1)==len(ha2):
					return True
				# 两个字符不同，意味着 当字符数==1 长度-1 在 + 换回来的在 hash 表中 则+1
				elif k1!=k2 and (len(ha1)-(v1==1)+(k2 not in ha1)==(len(ha2)-(v2==1)+(k1 not in ha2))):
					return True

		
		return False

if __name__ == "__main__":
	s=Solution().isItPossible
	print(s("a","bb"))