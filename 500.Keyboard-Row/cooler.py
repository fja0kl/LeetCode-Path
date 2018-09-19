"""
直接运算，最后判断行；count1+count2+count3 = 1:确保所有字母都在同一行；否则三者之和肯定大于1
所有判断行，最后判断是否同一行
"""
class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        list1 = ['Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p']
        list2 = ['A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l']
        list3 = ['Z','X','C','V','B','N','M','z','x','c','v','b','n','m']
        list4 = []
        for word in words:
            count1, count2, count3 = 0,0,0
            for c in word:#单独运算，最后判断
                if c in list1:
                    count1 = 1
                if c in list2:
                    count2 = 1
                if c in list3:
                    count3 = 1
            if (count1+count2+count3 == 1): list4.append(word)#可以断定所有字母都在同一行中；妙
        return list4 
