from lib.test import *

class Solution:

	def __init__(self):
		"""
		docstring
		"""
		self.prime=[]
		self.factor2=0


	def smallestValue(self, n: int) -> int:
		prevn=n
		while(n%2==0):
			self.factor2+=1
			n=n//2
		i=3
		while(i<n):
			if n%i==0:
				self.prime.append(i)
				n=n//i
				i=3
			else:
				i+=2
		if n!=1:
			self.prime.append(n)

		n=self.factor2*2+sum(self.prime)
		self.factor2=0
		self.prime=[]
		if prevn==n:
			return n
		else:
			return self.smallestValue(n)

if __name__ == "__main__":
	s=Solution().smallestValue(14)
	print(s)