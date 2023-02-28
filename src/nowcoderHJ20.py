import sys
""" HJ20 密码验证合格程序 
描述

密码要求:

1.长度超过8位

2.包括大小写字母.数字.其它符号,以上四种至少三种
3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换行）

数据范围：输入的字符串长度满足 1≤n≤100 1≤n≤100 
输入描述：

一组字符串。
输出描述：

如果符合要求输出：OK，否则输出NG
"""
# #字符串
""" 条件3使用hash表存储长度为3的子串，然后搜索是否存在重复 """
def check(s:str)->str:
    if len(s)<8:
        return "NG"
    kind=[0,0,0,0]
    for c in s:
        if c.isnumeric():
            kind[0]=1
        elif c.islower():
            kind[1]=1
        elif c.isupper():
            kind[2]=1
        elif not c.isspace():
            kind[3]=1

    if sum(kind)<3:
        return "NG"
    
    hash=set()
    for i in range(len(s)-3):
        if s[i:i+3] in hash:
            return "NG"
        hash.add(s[i:i+3])
    return "OK"


for line in sys.stdin: 
    print(check(line))
