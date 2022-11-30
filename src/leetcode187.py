from typing import List
import collections


# #hash 
""" 
统计长度为10的字符串出现次数, 出现次数大于1 添加到结果序列当中

做法很简单将长度为10的字符串作为hashtable key, 一旦出现则value ++

复杂度O(NL) L=10
"""
class Solution:
	def findRepeatedDnaSequences(self, s: str) -> List[str]:
		d=collections.defaultdict(int)
		for i in range(len(s)-10+1):
			key=s[i:i+10]
			d[key]+=1
		ans=[]
		for k in d:
			if d[k]>1:
				ans.append(k)
		return ans

"""
#位运算 #滑动窗口

还可以使用位运算来优化时间复杂度， ACGT 可以使用00 01 10 11 即0-3整数来表示

那么一个10位字符串唯一对应一个20 bit 整数 可以使用int 的前20位来维护.

结合一个滑动窗口就不用遍历整个字符串就能得到key, 具体做法如下:

窗口右移对应两个步骤
1. x=x<<2: 将所有数据左移2bit 获得空位
2. x|bin[ch]: 将新的数据放入,使用 or 很显然
删除左侧多出来的2bit数据
x&((1 << (20)) - 1)

1左移20位 到达 21位 成为 100000000000000000000 -1 得到 111111111111111111111

左侧多出来的位置都是0 显然做个 & 即可
"""

L = 10
bin = {'A': 0, 'C': 1, 'G': 2, 'T': 3}

class Solution1:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        if n <= L:
            return []
        ans = []
        x = 0
        for ch in s[:L - 1]:
            x = (x << 2) | bin[ch]
        cnt = collections.defaultdict(int)
        for i in range(n - L + 1):
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1)
            cnt[x] += 1
            if cnt[x] == 2:
                ans.append(s[i : i + L])
        return ans

""" 作者：力扣官方题解
链接：https://leetcode.cn/problems/repeated-dna-sequences/solutions/1035568/zhong-fu-de-dnaxu-lie-by-leetcode-soluti-z8zn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 """

if __name__ == "__main__":
	s=Solution().findRepeatedDnaSequences
	ans=s("AAAAAAAAAAA")
	print(ans)