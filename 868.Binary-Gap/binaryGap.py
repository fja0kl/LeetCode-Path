"""
要尽可能多用内置函数；
"""

class Solution:
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        binN = bin(N)[2:]
        if binN.count('1') <= 1:
            return 0
        start = binN.find('1')
        res = 0
        for i in range(start+1, len(binN), 1):
            if binN[i] == '1':
                res = max(res, i-start)
                start = i#start要及时更新；只要找到1，就更新
        
        return res
