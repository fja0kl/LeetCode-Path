class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = s.split()
        l = []
        for item in t:
            l.append(item[::-1])
        
        return " ".join(l)
