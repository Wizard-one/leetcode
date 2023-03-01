import math
"""  题目描述
若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，从已有的 N （ N 为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。

输入:

有一个正偶数 n ，表示待挑选的自然数的个数。后面给出 n 个具体的数字。

输出:

输出一个整数 K ，表示你求得的“最佳方案”组成“素数伴侣”的对数。

数据范围： 1≤n≤100 1≤n≤100  ，输入的数据大小满足 2≤val≤30000 2≤val≤30000  """

# #二分图 #匈牙利算法 #素数

def isPrime(x):
    if x<=3:
        return x>1
    for i in range(2, int(math.sqrt(x)+1)):
        if x%i ==0:
            return False
    else:
        return True

#该odd是否有匹配的even，返回boolean值   
def match(odd):
# 对偶数进行遍历，看是否与该奇数配对
    for i in range(n):
    # 若两数和为素数且该偶数在这轮循环中没有被访问过
        if isPrime(odd+ evens[i]) and vis[i]==0:
            # 将该偶数标记为已访问
        	vis[i]=1
			# p[i]=odd 为该偶数对应的odd储存值，如果该偶数没有奇数odd匹配，则为0，否则返回所匹配的odd
			# 如果p[i]还未匹配或者 p[i]已经有其他匹配的odd2，且该match(odd2)还有其他可以匹配的偶数(True)
            if p[i]==0 or match(p[i]):
            	# 取代原来的p[i]=odd2，变为 p[i]=odd
                p[i]=odd
                return True
    return False
                
    

while True:
    try:
        n = int(input())
        nums = list(map(int,input().split()))
        odds = []
        evens = []
        for num in nums:
            if num%2==0:
                evens.append(num)
            else:
                odds.append(num)
        m = len(odds)
        n = len(evens)
        s = 0
        p=[0]*n
        for num in odds:
        #每一次循环的vis必须要清空
            vis = [0]*n
            if match(num):
                s+=1
        print(s)
        
    except:
        break

