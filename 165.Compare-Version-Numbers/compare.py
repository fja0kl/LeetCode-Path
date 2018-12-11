"""
重要的是要补全,两个列表长度相同.

对划分后的列表0补全;
"""
class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1_list, v2_list = version1.split("."), version2.split(".")
        v1n = [int(k) for k in v1_list]
        v2n = [int(k) for k in v2_list]
        l1, l2 = len(v1n), len(v2n)
        max_l = max(l1, l2)
        if l1 < max_l:
            v1n.extend([0] * (max_l - l1))
        if l2 < max_l:
            v2n.extend([0] * (max_l - l2))
        for i in range(max_l):
            if v1n[i] < v2n[i]:
                return -1
            elif v1n[i] > v2n[i]:
                return 1
        return 0
