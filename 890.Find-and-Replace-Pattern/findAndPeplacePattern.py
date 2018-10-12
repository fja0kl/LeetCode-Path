"""
本质上是一种对应关系；可以对应到字母上，也可以对应到数字上。

之前的错误在于：
当两个连续的对应关系相同时，我就让程序退出了，忽略了之后的序列---导致错误，没有遍历完成
"""
class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        p = self.getPattern(pattern)
        res = []
        
        for word in words:
            if self.getPattern(word) == p:
                res.append(word)
        
        return res
        
    def getPattern(self, pattern):
        patternHash = {}
        p = ""
        idx = 0
        for i in pattern:
            if i not in patternHash:
                patternHash[i] = idx
                idx += 1
            p += str(patternHash[i])
        return p
            
