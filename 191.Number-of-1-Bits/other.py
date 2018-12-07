# 二进制表示中有多少个'1'
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        binN = bin(n)
        return binN.count('1')
