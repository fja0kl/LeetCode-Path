"""
有点复杂：使用“位运算”能更简单
"""
class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        xbin = bin(x)[2:]
        ybin = bin(y)[2:]
        maxlen = max(len(xbin),len(ybin))
        
        if x<y:
            xbin = '0'*(maxlen-len(xbin)) + xbin
        else:
            ybin = '0'*(maxlen-len(ybin)) + ybin
        
        return sum([abs(int(xbin[i])-int(ybin[i])) for i in range(maxlen)])


    def betterhammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        return bin(x^y)[2:].count('1')
        #^位异或运算，结果是对应的整数，bin变成二进制字符串，然后对'1'计数(不同)    
