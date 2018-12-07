"""
string.zfill(len): 使用0对字符串填充到指定长度.
list[::-1]: 用来翻转字符串,列表
"""
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        binN = bin(n)[2:].zfill(32)
        revN = binN[::-1]
        return int(revN, 2)
