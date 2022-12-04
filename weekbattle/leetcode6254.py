from typing import List
# #谜语人 #排序

""" 
6254. 划分技能点相等的团队
寻找拥有相同和的两个数的组合，返回这些组合的乘积之和
"""
class Solution:
	def dividePlayers(self, skill: List[int]) -> int:
		skill.sort()#排序
		ans=[]
		s=skill[-1]+skill[0]
		for i in range(int(len(skill)/2)):#相同和显然就是排序之后一头一尾
			if skill[i]+skill[-1-i]!=s:#遇到不同和直接退出
				return -1
			ans.append((skill[i],skill[-1-i]))
		s=0
		for p in ans:
			s+=p[0]*p[1]
		return s

if __name__ == "__main__":
	s=Solution().dividePlayers
	v=s([3,2])
	print(v)
	