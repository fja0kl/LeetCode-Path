class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        abin = list(bin(num)[2:])
        res = []
        for i in abin:
            if i == '0':
                res.append('1')
            else:
                res.append('0')
        
        res = "".join(res)
        return int(res,2)
