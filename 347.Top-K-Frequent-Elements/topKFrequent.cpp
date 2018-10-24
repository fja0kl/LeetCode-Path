"""
先计数：统计每个数字出现的次数；
然后依据出现次数排序；
取前k个项的键。
"""
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        cnt = {}
        for i in nums:
            cnt[i] = cnt.get(i, 0) + 1
        b = sorted(cnt, key = (lambda key: cnt[key]), reverse=True)#直接对cnt字典排序，依据字典的值降序排序；然后保留字典的键值--b全是键值
	# cnt.items():将cnt转换成了元组项，不可修改
        
        return b[:k]
