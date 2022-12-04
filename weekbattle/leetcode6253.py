
# #字符串 
""" 6253. 回环句
检测单词结尾与下一个单词开头是否相同
 """

class Solution:
	def isCircularSentence(self, sentence: str) -> bool:
		sentence=sentence.split()
		if sentence[0][0]!=sentence[-1][-1]:
			return False
		for i in range(1,len(sentence)):
			if sentence[i][0]!=sentence[i-1][-1]:
				return False
		return True
		