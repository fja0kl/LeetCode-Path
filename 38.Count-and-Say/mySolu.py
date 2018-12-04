"""
主要问题在于:连续字母的统计;
自己写时,陷在单个键值的字典里---所以,都是基于字典的操作,比较复杂:完成单个字典的更新,当需要添加新键值时,对字典键值的删除;

New: 获取第一个键值的方法:
(k,v), = d.items()
"""
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        res = self.helper(self.countAndSay(n-1))
        
        return res
    
    def helper(self, a):
        cnt = {}
        res = ""
        if a == '1':
            return '11'
        
        for i in a:
            # 初始化:不在字典里
            if cnt.get(i, -1) == -1 and len(cnt) == 0:
                cnt[i] = cnt.get(i, 0) + 1
            # 当前字符在字典里
            elif cnt.get(i, -1) != -1 and len(cnt) == 1:
                cnt[i] += 1
            # 不在字典里,先将之前的统计信息添加到结果里,删除,再添加新的信息[避免将不连续的字符,统计成连续的]
            else:
                # 添加计数结果
                (k, v), = cnt.items()
                res = res + str(v) + k
                del cnt[k]
                # 添加新的计数
                cnt[i] = cnt.get(i, 0) + 1
        (k, v), = cnt.items()
        res = res + str(v) + k

        return res
