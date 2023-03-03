import sys
""" 
HJ70 矩阵乘法计算量估算

描述

矩阵乘法的运算量与矩阵乘法的顺序强相关。
例如：

A是一个50×10的矩阵，B是10×20的矩阵，C是20×5的矩阵

计算A*B*C有两种顺序：((AB)C)或者(A(BC))，前者需要计算15000次乘法，后者只需要3500次。
编写程序计算不同的计算顺序需要进行的乘法次数。

数据范围：矩阵个数：1≤n≤15 1≤n≤15 ，行列数：1≤rowi,coli≤100 1≤rowi​,coli​≤100 ，保证给出的字符串表示的计算顺序唯一。
进阶：时间复杂度：O(n) O(n) ，空间复杂度：O(n) O(n) 


输入描述：

输入多行，先输入要计算乘法的矩阵个数n，每个矩阵的行数，列数，总共2n的数，最后输入要计算的法则
计算的法则为一个字符串，仅由左右括号和大写字母（'A'~'Z'）组成，保证括号是匹配的且输入合法！
输出描述：

输出需要进行的乘法次数

  """
n=int(input())
mat=[]
for i in range(n): 
    size=input().split()
    mat.append((int(size[0]),int(size[1])))

order=input()

temp=[]
def trave(s:str):
    ans=0
    for c in s:
        if c!=")":
            temp.append(c)
        else:
            c1=temp.pop()
            c0=temp.pop()
            temp.pop()
            mat1=mat[ord(c1)-ord("A")]
            mat0=mat[ord(c0)-ord("A")]
            ans+=mat0[0]*mat0[1]*mat1[1]
            mat[ord(c0)-ord("A")]=(mat0[0],mat1[1])
            temp.append(c0)
    print(ans)

trave(order)
