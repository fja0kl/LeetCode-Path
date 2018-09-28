"""
规律发现

没有发现对角元素坐标之间的关系！！！
我都列出来了！
idiot
"""
class Solution:
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        rows = len(matrix)
        cols = len(matrix[0])
        for i in range(rows-1):
            for j in range(cols-1):
                if matrix[i][j] != matrix[i+1][j+1]:
                    return False
        
        return True
        
