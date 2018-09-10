"""
异或：本身和本身异或操作，结果为0;0和任意数异或结果还是本身
"""
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = dict()
        for i in nums:
            dic[str(i)] = dic.get(str(i), 0) + 1

        for key,value in dic.items():
            if value == 1:
                return int(key)

        return -1

    def betterSolution(self,nums):
        res = 0
        for val in nums:
            res ^= val
        return res
