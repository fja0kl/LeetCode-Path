class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in range(len(A)):
            A[i].reverse()#翻转,等价于A[i][::-1]
            for j in range(len(A[i])):
                A[i][j] = int(not A[i][j])
            
        return A
        
