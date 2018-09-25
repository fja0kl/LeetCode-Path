class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        set1 = set(nums1)
        set2 = set(nums2)
        candidate = set1.intersection(set2)
        res = []
        for i in candidate:
            cnt = min(nums1.count(i), nums2.count(i))
            res.extend([i]*cnt)
        
        return res
        
