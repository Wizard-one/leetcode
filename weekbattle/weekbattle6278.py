"""
6278. 统计能整除数字的位数

 给你一个整数 num ，返回 num 中能整除 num 的数位的数目。

如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。 """

class Solution:
	def countDigits(self, num: int) -> int:
		dig=[]
		res=num
		# 拆分位数
		while res>0:
			dig.append(res%10)
			res//=10
		# print(dig)
		count=0
		# 检查是否能整除
		for i in dig:
			if num%i==0:
				count+=1
		return count


if __name__ == "__main__":
	s=Solution().countDigits
	print(s(1))
