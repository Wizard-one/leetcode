from lib.test import *

""" 202. 快乐数

 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

    对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果这个过程 结果为 1，那么这个数就是快乐数。

如果 n 是 快乐数 就返回 true ；不是，则返回 false 。  """

# #hash #隐式链表 #双指针 #快慢指针

""" 首先要构思所有的可能性
1. 到达1,10,100,...,100000000 是快乐数
2. 陷入一个循环
3. 膨胀到无穷大

而考虑3 位数999下一个状态转移为 243, 9999->324 就该理解 膨胀超出整数极限是不可能的

那么陷入循环就类似在一个带环的单链表中 判断是否存在环, 对应的求解方法就是有
1. hash 表
2. 快慢指针

由此问题解决
 """
class Solution:
    def isHappy(self, n: int) -> bool:
        walk=set()
        s=0
        while(n!=1):
            while(n>0):
                i=n%10
                n=n//10
                s+=i*i
                # print(i,s)
            if s in walk:
                return False
            else:
                walk.add(s)
                n=s
                s=0
        return True

if __name__ == "__main__":
    s=Solution().isHappy
    print(s(2))
