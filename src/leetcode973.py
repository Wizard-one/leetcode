from lib.test import *

#  #排序 #稳定排序
class Solution:
	def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
		dis=list()
		for p in points:
			dis.append((p[0]**2+p[1]**2,p[0],p[1]))
		dis.sort(key=lambda x: x[0])
		ans=[]
		for it in dis:
			if k>0:
				ans.append([it[1],it[2]])
				k-=1
			else:
				break
		return ans
		


if __name__ == "__main__":
	s=Solution().kClosest
	ans=s([[3,3],[5,-1],[-2,4]],1)
	print(ans)
		