"""
排序：奇数列和欧数列；
如果两个字符串奇数列和欧数列相同，则两个字符串special equivalent；
以奇数列和欧数列作为一个元组，添加到集合里。

集合set：特性，元素唯一性；
不用管结果是什么，直接添加到集合里；
"""
class Solution:
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        res = set()
        for word in A:
            c1, c2 = word[0::2], word[1::2]
            res.add((''.join(sorted(c1)), ''.join(sorted(c2))))
        
        return len(res)
