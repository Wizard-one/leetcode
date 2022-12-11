# #设计 #双指针
""" 给你一个整数 n ，表示下标从 0 开始的内存数组的大小。所有内存单元开始都是空闲的。

请你设计一个具备以下功能的内存分配器：

    分配 一块大小为 size 的连续空闲内存单元并赋 id mID 。
    释放 给定 id mID 对应的所有内存单元。

注意：

    多个块可以被分配到同一个 mID 。
    你必须释放 mID 对应的所有内存单元，即便这些内存单元被分配在不同的块中。

实现 Allocator 类：

    Allocator(int n) 使用一个大小为 n 的内存数组初始化 Allocator 对象。
    int allocate(int size, int mID) 找出大小为 size 个连续空闲内存单元且位于  最左侧 的块，分配并赋 id mID 。返回块的第一个下标。如果不存在这样的块，返回 -1 。
    int free(int mID) 释放 id mID 对应的所有内存单元。返回释放的内存单元数目。
 """
class Allocator:

	def __init__(self, n: int):
		self.loc=[0 for _ in range(n)]

	def allocate(self, size: int, mID: int) -> int:
		# 用双指针来实现内存空间的检测
		l=0
		r=size-1
		while r<len(self.loc):
			pr=r
			pl=l
			for i in range(l,r+1):
				if self.loc[i]!=0:
					# 检测到数组已经分配，则l边界变为i+1
					l=i+1
					while(l<len(self.loc)-size and self.loc[l]!=0):
						l+=1#持续移动直到有未分配区间
					r=l+size-1#更新右区间
					break
			if pr==r and pl==l:#如果区间不变，那么说明可分配
				break
		if l>=len(self.loc) or r >=len(self.loc):
			return -1
		for i in range(l,r+1):
			self.loc[i]=mID
		# print(self.loc)
		return l
		

	def free(self, mID: int) -> int:
		# 释放比较简单
		count=0
		for i in range(len(self.loc)):
			if self.loc[i]==mID:
				count+=1
				self.loc[i]=0
		# print(self.loc)
		return count

if __name__ == "__main__":
	loc=Allocator(10)
	loc.allocate(1, 1)
	loc.allocate(1, 2)
	loc.allocate(1, 3)
	loc.free(2)
	loc.allocate(3, 4)
	loc.allocate(1, 1)
	loc.allocate(1, 1)
	loc.free(1)
	loc.allocate(4, 2)
	loc.free(7)
