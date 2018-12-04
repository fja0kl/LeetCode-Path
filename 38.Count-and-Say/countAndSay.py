"""
单个字母计数,单个变量就可以实现,不用使用字典!!!

New: 添加额外字符,保证遍历原始输入时不会发生溢出
"""
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        # 保证不会越界
        pre = self.countAndSay(n-1) + '0'
        cnt = 1 # 计数
        res = "" 
        for i in range(len(pre)-1):# 对(n-1)th返回结果进行遍历,统计连续字母出现次数; -1:保证遍历的是原字符串
            if pre[i] == pre[i+1]:#连续相同字母
                cnt += 1
            else:#不连续,结果更新,完成单个字母的count & say,同时重置cnt
                res = res + str(cnt) + pre[i]
                cnt = 1 
                
        return res
