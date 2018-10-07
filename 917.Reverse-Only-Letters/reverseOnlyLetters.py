"""
双指针
"""
class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        S = list(S)
        left, right = 0, len(S)-1
        while(left<=right):
            if(S[left].isalpha() and S[right].isalpha()):
                S[left], S[right] = S[right], S[left]
                left += 1
                right -= 1
            elif S[left].isalpha() == False:
                left += 1
            elif S[right].isalpha() == False:
                right -= 1
        
        return "".join(S)
