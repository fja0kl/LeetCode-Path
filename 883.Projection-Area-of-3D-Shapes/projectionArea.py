"""
top是元素中非零的个数；
front是每行数据的最大值之和；一行表示图中的一列x=i这一列
side是每列数据的最大值之和；一列表示图中的一行y=i这一行

"""
class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        zeroes, front, side = 0, 0, 0
        for i in range(len(grid)):
            #top += sum(grid[i])#求法不对，应该是非零个数
            zeroes += grid[i].count(0)
            front += max(grid[i])
            side += max([grid[j][i] for j in range(len(grid))])
        
        top = len(grid)**2 - zeroes        
        return top+front+side
