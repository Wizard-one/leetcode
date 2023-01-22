from lib.test import *

""" 
241. 为运算表达式设计优先级

给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。
"""
# #分治
class Solution:

	""" 
	首先思考一个基础case 1+2+3 如何进行括号分割， 

	会发现是通过运算符进行分割，(1)+(2+3) (1+2)+(3) 那么我们只需按照运算符将字符串拆分为左边与右边的运算组合即可

	停止拆分的条件是字符串中没有运算符,这种情况直接返回符号

	需要注意的是吗,一个运算符左右可能会返回多种可能性  例如 1+((1)*(2+3)) 1+((1*2)+(3)) 右侧就有2种可能性

	所以右侧返回的不是单个值,而是一个list 那么就组合左右两个list的结果就完成了一个运算符的计算
	"""
	def diffWaysToCompute(self, expression: str) -> List[int]:
		ans=[]
		for i in range(len(expression)):
			c=expression[i]
			# 如果c为运算符,进行拆分
			if c in ["+","-","*"]:
				# 左边子串
				left=self.diffWaysToCompute(expression[:i])
				# 右边子串
				right=self.diffWaysToCompute(expression[i+1:])
				# 左右都有多种可能性，可能性的组合是 left*right, 对当前运算符进行左右组合
				for k in left:
					for j in right:
						if c=="*":
							ans.append(k*j)
						elif c=="+":
							ans.append(k+j)
						elif c=="-":
							ans.append(k-j)
		# 如果没有运算符, 直接返回数字
		if len(ans)==0:
			ans=[int(expression)]
		return ans

if __name__ == "__main__":
	s=Solution().diffWaysToCompute
	print(s("2*3-4*5"))
