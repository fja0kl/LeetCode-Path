#查找最大值，对应下标
class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        # 最大值的下标
        iMax = -1
        maxVal = -1
        for i, v in enumerate(A):
            if v > maxVal:
                maxVal = v
                iMax = i
            
        return iMax
