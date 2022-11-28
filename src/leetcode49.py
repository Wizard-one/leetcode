from typing import List
import collections
# #hash #排序 #构造
""" 
字母异位词分组

问题的核心是如何设计hash 的key - value

字母异位词的定义是两个字符串是否拥有相同的字母数量,进一步来说就是将字符串s 使用 这就转而确定问题了需要使用hash表

但是如何使用hash表呢? 第一个想法是通过hash统计字符串s的字母数量, 每一个字符串s都建一个自己的hash表,然后逐个对比不同字符串hash表是否一致.

这样显然是O(n^2)的复杂度无法通过问题. 此时就可以发现, **对比hash表一致** 这就说明了每一个字母异位词都可以有唯一的key, 然后value存储不同的字母异位词即可. 

那么问题就转化为, 如何构造key?

直接使用字母数量的 hash table 作为key,显然难以维护. 换一个想法,字母异位词在什么情况下可以变成相同的:

答案就是**排序**. 那么到此为止问题已经出来了: 使用排序之后的字母异位词作为key value存储字母异位词即可.
"""
class Solution:
	def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
		d=collections.defaultdict(list)
		for s in strs:
			k=''.join(sorted(s))
			d[k].append(s)
		ans=[]
		for k in d:
			ans.append(d[k])
		return ans

if __name__ == "__main__":
	s=Solution().groupAnagrams
	ans=s(["eat","tea","tan","ate","nat","bat"])
	print(ans)

