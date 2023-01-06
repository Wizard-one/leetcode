from lib.test import *
"""
22. 括号生成

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
"""

#  [[20]] [[1249]] #回溯 #递归 #字符串
class Solution:
    """ 
    由于要遍历所有选择所以使用决策树分析结合回溯求解

    需要注意的是 左右括号需要使用不同的标记变量来统计备选

    而括号是否合法就是决策树剪枝的条件，使用栈来进行维护。
    """
    def __init__(self) -> None:
        self.ans=[]


    def generateParenthesis(self, n: int) -> List[str]:
        rwait=n #标记右括号剩余数目
        lwait=n #标记左括号剩余数目
        stdepth=0 #标记括号栈深度
        walk=[]
        self.backtrack(rwait,lwait,stdepth,walk)
        return self.ans

    def backtrack(self,rwait:int,lwait:int,stdepth:int,walk:List[str]):
        # 右括号用完说明已经到栈底
        if rwait==0:
            self.ans.append("".join(walk))
            return

        # 左括号随便用直到用空为止
        if lwait>0:
            lwait-=1
            stdepth+=1#加一个左括号，栈深度+1
            walk.append("(")
            self.backtrack(rwait,lwait,stdepth,walk)
            # 撤销选择
            stdepth-=1
            walk.pop()
            lwait+=1
        
        #只有当栈深度不为0时才可以添加右括号
        if stdepth>0:
            stdepth-=1#加一个右括号，栈深度-1
            rwait-=1
            walk.append(")")
            self.backtrack(rwait,lwait,stdepth,walk)
            # 撤销选择
            walk.pop()
            rwait+=1
            stdepth+=1
            
if __name__ == "__main__":
    s=Solution().generateParenthesis
    print(s(3))


        
        
