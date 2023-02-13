from lib.test import *
""" 2513. 最小化两个数组中的最大值
给你两个数组 arr1 和 arr2 ，它们一开始都是空的。你需要往它们中添加正整数，使它们满足以下条件：

    arr1 包含 uniqueCnt1 个 互不相同 的正整数，每个整数都 不能 被 divisor1 整除 。
    arr2 包含 uniqueCnt2 个 互不相同 的正整数，每个整数都 不能 被 divisor2 整除 。
    arr1 和 arr2 中的元素 互不相同 。

给你 divisor1 ，divisor2 ，uniqueCnt1 和 uniqueCnt2 ，请你返回两个数组中 最大元素 的 最小值 。 """ 

class Solution:

    def minimizeSet(self, d1: int, d2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:

        lcm = math.lcm(d1, d2)

        def check(x: int) -> bool:

            left1 = max(uniqueCnt1 - x // d2 + x // lcm, 0)

            left2 = max(uniqueCnt2 - x // d1 + x // lcm, 0)

            common = x - x // d1 - x // d2 + x // lcm

            return common >= left1 + left2

        return bisect_left(range((uniqueCnt1 + uniqueCnt2) * 2 - 1), True, key=check)
""" 
作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimize-the-maximum-of-two-arrays/solutions/2031827/er-fen-da-an-by-endlesscheng-y8fp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 """