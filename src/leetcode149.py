from lib.test import *
"""
149. 直线上最多的点数

给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
"""

# #数学 #hash

""" 
纯纯的体力活,直接暴力求解

确定一条直线需要 k b 两个参数,遍历所有点对求出对应的k, b 然后找出相同k,b 的点归到一个组内,求出最长组长即可

考虑到查找最长组的搜索效率,使用hash 表来维护一个组

需要处理的子问题
1. k=(y1-y2)/(x1-x2) b=(x1y2-x2y1)/(x1-x2) 使用浮点数精度存储不足,需要直接存储int
2. 处理 k=0/inf 的情况
3. hash 的key 如何构造

简单来考虑,直接存储 "(y1-y2)_(x1-x2)_(x1y2-x2y1)_(x1-x2)" 字符串 作为键值同时做
- k b 需要约化到最简
- 符号位单独处理

由此只需再遍历hash表就可以解决问题
"""
class Solution:
	def maxPoints(self, points: List[List[int]]) -> int:
		if len(points)==1:
			return 1
		table=collections.defaultdict(set)
		for i in range(len(points)):
			for j in range(i+1,len(points)):
				a=points[i][1]-points[j][1]
				b=points[i][0]-points[j][0]
				c=(points[i][0]*points[j][1]-points[i][1]*points[j][0])
				if c!=0:
					# 过原点
					gbc=math.gcd(b,c)
					c/=gbc
					bnew=b/gbc
				# 求最大公约数约化
				gab=math.gcd(a,b)
				a/=gab
				b/=gab
				key=""
				# 先存k
				if a>0 and b>0 or (a<0 and b<0):
					key+=f"{int(abs(a))}_{int(abs(b))}"
				elif a>0 and b<0 or (a<0 and b>0):
					key+=f"-{int(abs(a))}_{int(abs(b))}"
				elif b==0:
					key+=f"inf_{points[i][0]}"
				else:
					key+=f"0_{points[i][1]}"
				# 再存b
				if c>0 and bnew>0 or (c<0 and bnew<0):
					key+=f"{int(abs(c))}_{int(abs(bnew))}"
				elif c>0 and bnew<0 or (c<0 and bnew>0):
					key+=f"-{int(abs(c))}_{int(abs(bnew))}"
				
				table[key].add(i)
				table[key].add(j)
		ans=0
		# print(table)
		for k in table:
			ans=max(ans,len(table[k]))
		return ans

if __name__ == "__main__":
	s=Solution().maxPoints
	print(s([[3,3],[1,4],[1,1],[2,1],[2,2]]))
