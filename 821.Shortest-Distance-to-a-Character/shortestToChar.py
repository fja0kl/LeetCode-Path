"""
先确定字符在S串里的所有下标；
之后计算每个字符到下标的距离，取最小值

比较复杂
"""
class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        indices = []
        for i in range(len(S)):
            if S[i] == C:
                indices.append(i)
        res = []
        for i in range(len(S)):
            dist = min([abs(i-idx) for idx in indices])
            res.append(dist)
        
        return res
