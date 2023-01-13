from lib.test import *

""" 给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。

实现 Solution class:

    Solution(int[] nums) 使用整数数组 nums 初始化对象
    int[] reset() 重设数组到它的初始状态并返回
    int[] shuffle() 返回数组随机打乱后的结果
 """
# #设计 #概率
""" 直接调库,依托答辩 """
class Solution:

    def __init__(self, nums: List[int]):
        self.arr1 = nums


    def reset(self) -> List[int]:
        return self.arr1


    def shuffle(self) -> List[int]:
        shuffArr = self.arr1.copy()
        random.shuffle(shuffArr)
        return shuffArr


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()



# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()