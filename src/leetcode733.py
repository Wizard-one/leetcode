from typing import List 
# #递归 #深度优先搜索
class Solution:
	def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
		if image[sr][sc]==color:
			return image
		image=self.floodCell(image,sr,sc,image[sr][sc],color)
		return image

	def floodCell(self,image:List[List[int]],r:int,c:int,v:int,color:int)->List[List[int]]:
		m=len(image)
		n=len(image[0])
		if (r>=m or r<0) or c>=n or c<0 or image[r][c]!=v:
			return image
		elif image[r][c]==v:
			image[r][c]=color
		# 这一步体现为深度优先，先遇到边界再开始回朔
		image=self.floodCell(image,r-1,c,v,color)
		image=self.floodCell(image,r+1,c,v,color)
		image=self.floodCell(image,r,c-1,v,color)
		image=self.floodCell(image,r,c+1,v,color)
		return image

if __name__ == "__main__":
	image = [[0,0,0],[0,0,0]]
	# image = [[1,1,1],[1,1,0],[1,0,1]]
	sr = 0
	sc = 0
	newColor = 0
	s=Solution().floodFill
	ans=s(image,sr,sc,newColor)
	print(ans)