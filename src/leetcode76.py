from lib.test import *


""" 76. 最小覆盖子串
 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

    对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
    如果 s 中存在这样的子串，我们保证它是唯一的答案。 """

# #滑动窗 #字符串 #子串
class Solution:
    """ 
    覆盖问题，用一个滑动窗从头滑到尾，使用hash表维护子串覆盖情况，最小子串就是通过滑动窗缩减大小来实现
    """
    def minWindow(self, s: str, t: str) -> str:
        tabt=collections.Counter(t)
        l,r=0,0
        st,minlen=0,len(s)+1 #额外维护返回结果的开始与长度，因为查询的是最小长度,滑动窗内部并不直接维护结果串

        vaild=0 #记录合法的字符数目
        tabwin=collections.Counter()
        while(r<len(s)):
            c=s[r]
            if c in tabt:
                tabwin.update(c)
                if tabwin[c]==tabt[c]:
                    vaild+=1
            r+=1
            # 当子串为合法子串，开始缩减滑动窗大小
            while(vaild==len(tabt)):
                # 当前串还是合法子串时进行答案子串的维护
                if r-l<minlen:
                    st=l
                    minlen=r-l
                if s[l] in tabt:
                    # 由于是覆盖 当然可能出现 window 内部 tabwin[s[l]]>tabt[s[l]] 的情况，但此时无需更新vaild 因为还合法
                    if tabwin[s[l]]==tabt[s[l]]:
                        vaild-=1
                    tabwin[s[l]]-=1
                l+=1
        if minlen==len(s)+1:
            return ""
        return s[st:st+minlen]

if __name__ == "__main__":
    s=Solution().minWindow
    print(s("ADOBECODEBANC","ABC"))


