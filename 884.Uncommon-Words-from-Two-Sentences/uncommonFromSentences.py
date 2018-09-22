"""
集合的概念及其操作
^ : 对称差
A^B:在A中不在B中 ∪ 在B中不在A中
cool
"""

class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        #集合的概念
        listA = A.strip().split()
        listB = B.strip().split()
        candidate = set(listA) ^ set(listB)#对称差
        useless = set()
        for item in candidate:
            if listA.count(item) > 1 or listB.count(item) > 1:
                useless.add(item)
        
        return list(candidate-useless)
        
