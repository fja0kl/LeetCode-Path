class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        result = []
        for i in range(left,right+1):
            if self.helper(i):#调用同类函数，需要用self调用
                result.append(i)
                
        return result
    
    def helper(self,numb):
        digits = list(str(numb))
        
        for i in digits:
            if i =='0' or numb % int(i) != 0:
                return False
        return True
        
