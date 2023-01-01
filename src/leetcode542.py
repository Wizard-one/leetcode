from typing import List,Tuple
import collections

#  #广度优先搜索 #最短路 #matrix

class Solution:
    """ 
    问题最核心的是选择什么样的角度维护距离，从mat[i][j]==1 然后搜索最短路径就需要维护4个方向上搜索之后最小值。从 mat[i][j]==0 维护距离只需要通过广搜将周围的点逐渐累加距离即可

    例如只有1个0 那周围距离就是
    212
    101
    212

    随后考虑矩阵中有多个0的情况，采用多目标最短路中超级源的概念，将所有0联通到一个抽象的0，从抽象0到实体0之间距离1. 

    """
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        
        m=len(mat)
        n=len(mat[0])
        dist=[[0]*n for _ in range(m)]
        zp=[] 
        for i in range(m):
            for j in range(n):
                if not mat[i][j]:
                    zp.append((i,j))
        que=collections.deque(zp) # 这一步等价于将抽象0 pop之后 append所有0 
        down=set(zp)

        while que:
            x,y=que.popleft()
            for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                if (i>=0 and i<m) and (j>=0 and j<n) and (i,j) not in down:
                    down.add((i,j))
                    que.append((i,j))
                    dist[i][j]=dist[x][y]+1

        return dist

if __name__ == "__main__":
    ma=[[0,0,0]]
    s=Solution().updateMatrix
    s(ma)