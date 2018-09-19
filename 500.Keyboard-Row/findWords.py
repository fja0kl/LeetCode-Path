"""
集合：元素之间没有顺序；
交集、并集、差集；子集、父集
列表：元素之间有顺序；

子集的概念

将重复操作独立开，聚集到原操作上。
"""
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1 = set('qwertyuiop')
        row2 = set('asdfghjkl')
        row3 = set('zxcvbnm')
        
        res = []
        
        for word in words:
            target = set(word.lower())
            if target.issubset(row1) or target.issubset(row2) or target.issubset(row3):
                res.append(target)
        
        return res

