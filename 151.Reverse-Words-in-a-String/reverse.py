"""
python list逆转:
1. list.reverse()
2. list = list[::-1]
"""
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split()
        words.reverse()
        
        return " ".join(words)
