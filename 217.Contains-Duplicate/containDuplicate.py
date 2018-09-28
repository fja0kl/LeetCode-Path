"""
Pythonic code
"""

class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        return len(set(nums)) != len(nums)