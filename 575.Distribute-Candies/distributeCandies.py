"""
Use build-in functions more.

最多是list的一半(每种糖果都有两个)；
其他就是set()的长度
"""
class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        return min(len(set(candies)), len(candies)//2)
