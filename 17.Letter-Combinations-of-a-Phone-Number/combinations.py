"""
排列问题，依次在上次结果中添加新元素
"""
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits: return []
        
        maps = {'2':'abc',
                '3':'def',
               '4':'ghi',
               '5':'jkl',
               '6':'mno',
               '7':'pqrs',
               '8':'tuv',
               '9':'wxyz',}

        res = ['']
        temp = []
        for i in digits:
            for ss in maps[i]:
                for s in res:#在上次结果中添加新元素
                    temp.append(s+ss)
            res = temp
            temp = []
            
        return res
