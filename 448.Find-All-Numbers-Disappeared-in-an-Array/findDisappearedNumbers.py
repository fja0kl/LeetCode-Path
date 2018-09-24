class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        numsSet = set(nums)
        allSet = set(range(1,len(nums)+1))
        
        return list(allSet-numsSet)
