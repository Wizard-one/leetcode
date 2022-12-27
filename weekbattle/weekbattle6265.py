from lib.test import *
class Solution:
	def similarPairs(self, words: List[str]) -> int:
		setword=[set(w) for w in words]
		count=0
		for i in range(len(setword)):
			for j in range(i+1,len(setword)):
				if setword[i]==setword[j]:
					count+=1

		return count

if __name__ == "__main__":
	s=Solution().similarPairs
	ans=s(["aa","a","aaa","asd"])
	print(ans)