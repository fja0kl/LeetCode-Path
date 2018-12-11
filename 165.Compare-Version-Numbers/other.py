"""
另一种补全方法:

用小长度,遍历;如果长度超出,当前值设为0
"""
class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = [int(v) for v in version1.split('.')]
        v2 = [int(v) for v in version2.split('.')]
        # 长度不同,需要0补全
        for i in range(max(len(v1), len(v2))):
            j = v1[i] if i<len(v1) else 0
            k = v2[i] if i<len(v2) else 0
            if j<k:
                return -1
            elif j>k:
                return 1
        return 0
